// Copyright (C) 2005-2007 Garth N. Wells.
// Licensed under the GNU LGPL Version 2.1.
//
// First added:  2006-03-02
// Last changed: 2010-09-01
//
// This program illustrates the use of the DOLFIN nonlinear solver for solving
// the Cahn-Hilliard equation.
//
// The Cahn-Hilliard equation is very sensitive to the chosen parameters and
// time step. It also requires fines meshes, and is often not well-suited to
// iterative linear solvers.

// Begin demo

#include <dolfin.h>
#include "CahnHilliard2D.h"
#include "CahnHilliard3D.h"

using namespace dolfin;

// Initial conditions
class InitialConditions : public Expression
{
public:

  InitialConditions(const Mesh& mesh) : Expression(mesh.topology().dim())
  {
    dolfin::seed(2 + dolfin::MPI::process_number());
  }

  void eval(Array<double>& values, const Data& data) const
  {
    values[0]= 0.63 + 0.02*(0.5 - dolfin::rand());
    values[1]= 0.0;
  }

};

// User defined nonlinear problem
class CahnHilliardEquation : public NonlinearProblem
{
  public:

    // Constructor
    CahnHilliardEquation(const Mesh& mesh, const Constant& dt,
                         const Constant& theta, const Constant& lambda)
                       : reset_Jacobian(true)
    {
      // Initialse class (depending on geometric dimension of the mesh).
      // Unfortunately C++ does not allow namespaces as template arguments
      if (mesh.geometry().dim() == 2)
        init<CahnHilliard2D::FunctionSpace, CahnHilliard2D::BilinearForm, CahnHilliard2D::LinearForm>(mesh, dt, theta, lambda);
      else if (mesh.geometry().dim() == 3)
        init<CahnHilliard3D::FunctionSpace, CahnHilliard3D::BilinearForm, CahnHilliard3D::LinearForm>(mesh, dt, theta, lambda);
      else
        error("Cahn-Hilliard model is programmed for 2D and 3D only.");
    }

    // User defined residual vector
    void F(GenericVector& b, const GenericVector& x)
    {
      // Assemble RHS (Neumann boundary conditions)
      assemble(b, *L);
    }

    // User defined assemble of Jacobian
    void J(GenericMatrix& A, const GenericVector& x)
    {
      // Assemble system and RHS (Neumann boundary conditions)
      assemble(A, *a, reset_Jacobian);
      reset_Jacobian = false;
    }

    // Return solution function
    Function& u()
    { return *_u; }

    // Return solution function
    Function& u0()
    { return *_u0; }

  private:

    template<class X, class Y, class Z>
    void init(const Mesh& mesh, const Constant& dt, const Constant& theta,
              const Constant& lambda)
    {
      // Create function space and functions
      boost::shared_ptr<X> V(new X(mesh));
      _u.reset(new Function(V));
      _u0.reset(new Function(V));

      // Create forms and attach functions
      Y* _a = new Y(V, V);
      Z* _L = new Z(V);
      _a->u = *_u; _a->lmbda = lambda; _a->dt = dt; _a->theta = theta;
      _L->u = *_u; _L->u0 = *_u0;
      _L->lmbda = lambda; _L->dt = dt; _L->theta = theta;

      // Wrap pointers in a smart pointer
      a.reset(_a);
      L.reset(_L);

      // Set solution to intitial condition
      InitialConditions u_initial(mesh);
      *_u = u_initial;
    }

    // Function space, forms and functions
    boost::scoped_ptr<Form> a;
    boost::scoped_ptr<Form> L;
    boost::scoped_ptr<Function> _u;
    boost::scoped_ptr<Function> _u0;
    bool reset_Jacobian;
};


int main(int argc, char* argv[])
{
  dolfin_init(argc, argv);

  // Mesh
  UnitSquare mesh(96, 96);

  // Time stepping and model parameters
  Constant dt(5.0e-6);
  Constant theta(0.5);
  Constant lambda(1.0e-2);

  double t = 0.0;
  double T = 50*dt;

  // Create user-defined nonlinear problem
  CahnHilliardEquation cahn_hilliard(mesh, dt, theta, lambda);

  // Solution functions
  Function& u = cahn_hilliard.u();
  Function& u0 = cahn_hilliard.u0();

  // Create nonlinear solver and set parameters
  NewtonSolver newton_solver("lu");
  newton_solver.parameters["convergence_criterion"] = "incremental";
  newton_solver.parameters["maximum_iterations"] = 10;
  newton_solver.parameters["relative_tolerance"] = 1e-6;
  newton_solver.parameters["absolute_tolerance"] = 1e-15;

  // Save initial condition to file
  File file("cahn_hilliard.pvd", "compressed");
  file << u[0];

  // Solve
  while (t < T)
  {
    // Update for next time step
    t += dt;
    u0.vector() = u.vector();

    // Solve
    newton_solver.solve(cahn_hilliard, u.vector());

    // Save function to file
    file << std::make_pair(&(u[0]), t);
  }

  // Plot solution
  plot(u[0]);

  return 0;
}
