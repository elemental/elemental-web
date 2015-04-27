Linear Programs
===============
The following routines attempt to solve primal-dual pairs of (convex) quadratic
programs in either "direct" conic form,

.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \ge 0 \;\},

or "affine" conic form

.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h,\; s \ge 0 \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \ge 0 \;\}.

By default a Mehrotra Predictor-Corrector primal-dual
Interior Point Method is used.

.. toctree::

   :maxdepth: 1

   LP/direct
   LP/affine
