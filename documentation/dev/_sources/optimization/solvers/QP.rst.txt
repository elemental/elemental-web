Quadratic Programs
==================
The following routines attempt to solve primal-dual pairs of (convex) quadratic
programs in either "direct" conic form,

.. math::

   \min_x     & \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; -\frac{1}{2} r^T Q^\dagger r - b^T y \; | \; r = A^T y - z + c \in \text{range}(Q) \;\wedge\; z \ge 0 \;\},

or "affine" conic form

.. math::

   \min_{x,s} & \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \ge 0 \;\}, \\
   \max_{y,z} & \{\; -\frac{1}{2} r^T Q^\dagger r - b^T y - h^T z \; | \; r = A^T y + G^T z + c \in \text{range}(Q) \;\wedge\; z \ge 0 \;\}.

By default a Mehrotra Predictor-Corrector primal-dual
Interior Point Method is used.

Unpolished alternating direction methods for solving the box-constrained QP

.. math::

   \min_x \{\; \frac{1}{2} x^T Q x + c^T x  \; | \; l_b \le x \le u_b \;\}

are also available.

.. toctree::
   :maxdepth: 1

   QP/direct
   QP/affine
   QP/box
