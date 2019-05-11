Second-Order Cone Programs
==========================
The following routines attempt to solve primal-dual pairs of Second-Order Cone
Programs in either "direct" conic form,

.. math::

   \min_x     & \{\; c^T x  \; | \; A x = b \;\wedge\; x \in \mathcal{K} \;\},\\
   \max_{y,z} & \{\; - b^T y \; | \; A^T y - z + c = 0 \;\wedge\; z \in \mathcal{K} \;\},

or "affine" conic form

.. math::

   \min_{x,s} & \{\; c^T x  \; | \; A x = b \;\wedge\; G x + s = h\;\wedge\; s \in \mathcal{K} \;\}, \\
   \max_{y,z} & \{\; - b^T y - h^T z \; | \; A^T y + G^T z + c = 0 \;\wedge\; z \in \mathcal{K} \;\},

where :math:`\mathcal{K}` is a product of Second-Order (a.k.a. *Lorentz*, or *icecream*) Cones of the form

.. math::

   \mathcal{Q}_m = \{ (\chi_0,x_1) \in \mathbb{R}^m : \chi_0 \ge \| x_1 \|_2 \}.

By default a Mehrotra Predictor-Corrector primal-dual
Interior Point Method is used.

.. toctree::
   :maxdepth: 1

   SOCP/direct
   SOCP/affine
