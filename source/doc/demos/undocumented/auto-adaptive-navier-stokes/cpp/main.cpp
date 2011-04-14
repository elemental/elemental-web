// Copyright (C) 2010 Marie E. Rognes (meg@simula.no)
// Licensed under the GNU LGPL Version 3 or any later version
//
// First added:  2010-08-19
// Last changed: 2011-03-22

#include <dolfin.h>
#include "AdaptiveNavierStokes.h"

using namespace dolfin;

// No-slip boundary
class Noslip : public SubDomain
{
  bool inside(const Array<double>& x, bool on_boundary) const
  {
    return ((x[1] < DOLFIN_EPS || x[1] > 1.0 - DOLFIN_EPS) ||
            (on_boundary && abs(x[0] - 1.5) < 0.1 + DOLFIN_EPS));
  }
};

// Subdomain on which goal function should be defined
class Outflow : public SubDomain
{
  bool inside(const Array<double>& x, bool on_boundary) const
  {
    return x[0] > 4.0 - DOLFIN_EPS;
  }
};

// Applied pressure (Neumann boundary condition)
class Pressure : public Expression
{
  void eval(Array<double>& values, const Array<double>& x) const
  {
    values[0] = (4.0 - x[0])/4.0;
  }
};

int main() {

  parameters["allow_extrapolation"] = true;

  // Create mesh and function space
  Mesh mesh("channel_with_flap.xml");
  AdaptiveNavierStokes::BilinearForm::TrialSpace W(mesh);

  // Unknown
  Function w(W);

  // Define boundary condition
  Constant u0(0.0, 0.0);
  Noslip noslip;
  MeshFunction<dolfin::uint> noslip_markers(mesh, mesh.topology().dim() - 1, 1);
  noslip.mark(noslip_markers, 0);
  SubSpace W0(W, 0);
  DirichletBC bc(W0, u0, noslip_markers, 0);

  // Create variational formulation and assign coefficients
  Constant nu(0.02);
  AdaptiveNavierStokes::LinearForm F(W);
  Pressure p0;
  F.p0 = p0;
  F.nu = nu;
  F.w = w;

  // Create Jacobian and assign coefficients
  AdaptiveNavierStokes::BilinearForm dF(W, W);
  dF.nu = nu;
  dF.w = w;

  // Define variational problem
  VariationalProblem pde(F, dF, bc);

  // Define goal functional
  AdaptiveNavierStokes::GoalFunctional M(mesh);
  M.w = w;
  Outflow outflow;
  MeshFunction<dolfin::uint> outflow_markers(mesh, mesh.topology().dim()-1, 1);
  outflow.mark(outflow_markers, 0);
  M.exterior_facet_domains = outflow_markers;

  // Give reference and don't plot mesh in each iteration
  pde.parameters("adaptivity")["reference"] = 0.40863917;
  pde.parameters("adaptivity")["plot_mesh"] = false;

  // Solve problem with goal-oriented error control to given tolerance
  double tol = 1.e-5;
  pde.solve(w, tol, M);

  // Show timings
  summary();

  return 0;
}