SVD
===
Given an :math:`m \times n` matrix :math:`A`, a *Singular Value Decomposition* 
is a triplet :math:`(U,\Sigma,V)` such that

.. math::

   A = U \Sigma V^H,

where :math:`U^H U = I`, :math:`V^H V = I`, and :math:`\Sigma` is diagonal with
non-negative entries. The columns of :math:`U` are called 
*left singular vectors*, the columns of :math:`V` are called 
*right singular vectors*, and the first :math:`\text{min}(m,n)` diagonal 
entries of :math:`\Sigma` are called *singular values*.

The above constraints allow for a number of different
configurations::

1. A *full* SVD requires a square, :math:`m \times m` :math:`U`, a square,
   :math:`n \times n`, :math:`V`, and an :math:`m \times n` :math:`\Sigma`.
2. A *thin* SVD only involves an :math:`m \times \text{min}(m,n)` :math:`U`,
   an :math:`\text{min}(m,n) \times n` :math:`V`, and a 
   :math:`\min(m,n) \times \min(m,n)` :math:`\Sigma`.
3. A *compact* SVD only keeps the singular triplets corresponding to nonzero
   singular values, and so its size is bounded by that of the thin SVD.
4. A *thresholded* SVD only keeps the singular triplets with singular values
   which are sufficiently large. Thus, *compact* SVDs are a special case of 
   thresholded SVDs.

Elemental currently provides support for thin and thresholded SVDs as well as
allowing for only the singular values to be computed.

`Implementation <https://github.com/elemental/Elemental/blob/master/src/lapack_like/spectral/SVD.cpp>`__

`Subroutines <https://github.com/elemental/Elemental/tree/master/src/lapack_like/spectral/SVD>`__

Computing singular values
-------------------------
The following routines form the singular values of :math:`A` in `s`. Note that 
`A` is overwritten in order to compute the singular values.

C++ API
^^^^^^^

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElSingularValues_s( ElMatrix_s A, ElMatrix_s s )
.. c:function:: ElSingularValues_d( ElMatrix_d A, ElMatrix_d s )
.. c:function:: ElSingularValues_c( ElMatrix_c A, ElMatrix_s s )
.. c:function:: ElSingularValues_z( ElMatrix_z A, ElMatrix_d s )
.. c:function:: ElSingularValuesDist_s( ElDistMatrix_s A, ElDistMatrix_s s )
.. c:function:: ElSingularValuesDist_d( ElDistMatrix_d A, ElDistMatrix_d s )
.. c:function:: ElSingularValuesDist_c( ElDistMatrix_c A, ElDistMatrix_s s )
.. c:function:: ElSingularValuesDist_z( ElDistMatrix_z A, ElDistMatrix_d s )

**TODO: Expert interfaces**

Computing Singular Value Decompositions
---------------------------------------
The following routines overwrite `A` with :math:`U`, `s` with the diagonal 
entries of :math:`\Sigma`, and `V` with :math:`V`. 

C++ API
^^^^^^^

.. cpp:function:: void SVD( Matrix<F>& A, Matrix<Base<F>>& s, Matrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

.. cpp:function:: void SVD( AbstractDistMatrix<F>& A, AbstractDistMatrix<Base<F>>& s, AbstractDistMatrix<F>& V, const SVDCtrl<Base<F>>& ctrl=SVDCtrl<Base<F>>() )

C API
^^^^^

.. c:function:: ElError ElSVD_s( ElMatrix_s A, ElMatrix_s s, ElMatrix_s V )
.. c:function:: ElError ElSVD_d( ElMatrix_d A, ElMatrix_d s, ElMatrix_d V )
.. c:function:: ElError ElSVD_c( ElMatrix_c A, ElMatrix_s s, ElMatrix_c V )
.. c:function:: ElError ElSVD_z( ElMatrix_z A, ElMatrix_d s, ElMatrix_z V )
.. c:function:: ElError ElSVDDist_s( ElDistMatrix_s A, ElDistMatrix_s s, ElDistMatrix_s V )
.. c:function:: ElError ElSVDDist_d( ElDistMatrix_d A, ElDistMatrix_d s, ElDistMatrix_d V )
.. c:function:: ElError ElSVDDist_c( ElDistMatrix_c A, ElDistMatrix_s s, ElDistMatrix_c V )
.. c:function:: ElError ElSVDDist_z( ElDistMatrix_z A, ElDistMatrix_d s, ElDistMatrix_z V )

**TODO: Expert interfaces**

Control structures
------------------

C++ API
^^^^^^^

.. cpp:type:: SVDCtrl<Real>

   .. cpp:member:: bool seqQR

      Whether or not sequential implementations should use the QR algorithm
      instead of a Divide and Conquer when computing singular vectors.
      When only singular values are requested, a bidiagonal DQDS algorithms is 
      always run.

   .. cpp:member:: double valChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when only computing singular values.

   .. cpp:member:: double fullChanRatio

      The minimum height/width ratio before preprocessing with a QR 
      decomposition when computing a full SVD.

   .. cpp:member:: bool thresholded
 
      If the sufficiently small singular triplets should be thrown away.
      When thresholded, a cross-product algorithm is used. This is often
      advantageous since tridiagonal eigensolvers tend to have faster 
      parallel implementations than bidiagonal SVD's.

   .. cpp:member:: bool relative

      If the tolerance should be relative to the largest singular value.

   .. cpp:member:: Real tol

      The numerical tolerance for the thresholding. If this value is kept at
      zero, then a value is automatically chosen based upon the matrix.

   .. cpp:function:: SVDCtrl()

      Sets ``seqQR=false``, ``valChanRatio=1.2``, ``fullChanRatio=1.5``,
      ``thresholded=false``, ``relative=true``, and ``tol=0``.

.. cpp:type:: SVDCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
^^^^^

.. c:type:: ElSVDCtrl_s

   .. c:member:: bool seqQR
   .. c:member:: double valChanRatio 
   .. c:member:: double fullChanRatio
   .. c:member:: bool thresholded
   .. c:member:: bool relative
   .. c:member:: float tol

.. c:type:: ElSVDCtrl_d

   .. c:member:: bool seqQR
   .. c:member:: double valChanRatio 
   .. c:member:: double fullChanRatio
   .. c:member:: bool thresholded
   .. c:member:: bool relative
   .. c:member:: double tol

.. c:function:: ElError ElSVDCtrlDefault_s( ElSVDCtrl_s* ctrl )
.. c:function:: ElError ElSVDCtrlDefault_d( ElSVDCtrl_d* ctrl )

   Initialize the default values for the control structure
   (``seqQR=false``, ``valChanRatio=1.2``, ``fullChanRatio=1.5``,
   ``thresholded=false``, ``relative=true``, and ``tol=0``)
