General (Gauss-Markov) Linear Model
===================================

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/solve/GLM.cpp>`__

`Example driver <https://github.com/elemental/Elemental/blob/master/examples/lapack_like/GLM.cpp>`__

.. math::

   \min_{X,Y} \| Y \|_F \;\;\; \text{subject to } A X + B Y = D.

C++ API
^^^^^^^

.. cpp:function:: void GLM( Matrix<F>& A, Matrix<F>& B, Matrix<F>& D, Matrix<F>& Y )
.. cpp:function:: void GLM( AbstractDistMatrix<F>& A, AbstractDistMatrix<F>& B, AbstractDistMatrix<F>& D, AbstractDistMatrix<F>& Y )

C API
^^^^^

.. c:function:: ElError ElGLM_s( ElMatrix_s A, ElMatrix_s B, ElMatrix_s D, ElMatrix_s Y )
.. c:function:: ElError ElGLM_d( ElMatrix_d A, ElMatrix_d B, ElMatrix_d D, ElMatrix_d Y )
.. c:function:: ElError ElGLM_c( ElMatrix_c A, ElMatrix_c B, ElMatrix_c D, ElMatrix_c Y )
.. c:function:: ElError ElGLM_z( ElMatrix_z A, ElMatrix_z B, ElMatrix_z D, ElMatrix_z Y )
.. c:function:: ElError ElGLMDist_s( ElDistMatrix_s A, ElDistMatrix_s B, ElDistMatrix_s D, ElDistMatrix_s Y )
.. c:function:: ElError ElGLMDist_d( ElDistMatrix_d A, ElDistMatrix_d B, ElDistMatrix_d D, ElDistMatrix_d Y )
.. c:function:: ElError ElGLMDist_c( ElDistMatrix_c A, ElDistMatrix_c B, ElDistMatrix_c D, ElDistMatrix_c Y )
.. c:function:: ElError ElGLMDist_z( ElDistMatrix_z A, ElDistMatrix_z B, ElDistMatrix_z D, ElDistMatrix_z Y )
