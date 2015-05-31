Control structures
==================

Python API
----------
**TODO**

C++ API
-------
.. cpp:enum:: PseudospecNorm

   .. cpp:enumerator:: PS_TWO_NORM

      Compute :math:`\{ \xi \in \mathbb{C} : \| (A - \xi I)^{-1} \|_2 > \frac{1}{\epsilon} \}`

   .. cpp:enumerator:: PS_ONE_NORM

      Compute :math:`\{ \xi \in \mathbb{C} : \| (A - \xi I)^{-1} \|_1 > \frac{1}{\epsilon} \}`

.. cpp:class:: SnapshotCtrl

   .. cpp:member:: Int realSize
   .. cpp:member:: Int imagSize

   .. cpp:member:: Int imgSaveFreq
   .. cpp:member:: Int numSaveFreq
   .. cpp:member:: Int imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. cpp:member:: Int imgSaveCount
   .. cpp:member:: Int numSaveCount
   .. cpp:member:: Int imgDispCount

   .. cpp:member:: std::string imgBase
   .. cpp:member:: std::string numBase

   .. cpp:member:: FileFormat imgFormat
   .. cpp:member:: FileFormat numFormat

   .. cpp:function::  SnapshotCtrl()

      All counters and dimensions are initially zero, all save/display 
      "frequencies" are set to -1 (no output), the basename strings are 
      initialized to "ps", the image format to ``PNG``, and the numerical 
      format to ``ASCII_MATLAB``.

   .. cpp:function:: void ResetCounts()

      Resets all counters to zero

   .. cpp:function:: void Iterate()

      Increments all counters by one

.. cpp:class:: PseudospecCtrl<Real>

   .. cpp:member::bool schur

   .. cpp:member:: bool forceComplexSchur

   .. cpp:member:: bool forceComplexPs

   .. cpp:member:: SchurCtrl<Real> schurCtrl

   .. cpp:member:: Int maxIts

   .. cpp:member:: Real tol

   .. cpp:member:: bool deflate

   .. cpp:member:: bool arnoldi

   .. cpp:member:: Int basisSize

   .. cpp:member:: bool reorthog

   .. cpp:member:: bool progress

   .. cpp:member:: SnapshotCtrl snapCtrl

.. cpp:class:: PseudospecCtrl<Base<F>>

   A particular case where the datatype is the base of the potentially complex
   type ``F``.

C API
-----
.. c:type:: ElSnapshotCtrl

   .. c:member:: ElInt realSize
   .. c:member:: ElInt imagSize

   .. c:member:: ElInt imgSaveFreq
   .. c:member:: ElInt numSaveFreq
   .. c:member:: ElInt imgDispFreq 

      Negative if no snapshots should be saved/displayed, 
      zero if only a final snapshot should be saved/displayed, and equal to 
      :math:`n > 0` if, in addition to a final snapshot, the partial results 
      should be output roughly overy `n` iterations (there is no output in the 
      middle of Impliclty Restarted Arnoldi cycles). 

   .. c:member:: ElInt imgSaveCount
   .. c:member:: ElInt numSaveCount
   .. c:member:: ElInt imgDispCount

   .. c:member:: const char* imgBase
   .. c:member:: const char* numBase

   .. c:member:: ElFileFormat imgFormat
   .. c:member:: ElFileFormat numFormat

.. c:function:: ElError ElSnapshotCtrlDefault( ElSnapshotCtrl* ctrl )
.. c:function:: ElError ElSnapshotCtrlDestroy( ElSnapshotCtrl* ctrl )

.. c:type:: ElPseudospecCtrl_s

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: float tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:type:: ElPseudospecCtrl_d

   .. c:member::bool schur

   .. c:member:: bool forceComplexSchur

   .. c:member:: bool forceComplexPs

   .. c:member:: ElSchurCtrl_s schurCtrl

   .. c:member:: ElInt maxIts

   .. c:member:: double tol

   .. c:member:: bool deflate

   .. c:member:: bool arnoldi

   .. c:member:: ElInt basisSize

   .. c:member:: bool reorthog

   .. c:member:: bool progress

   .. c:member:: ElSnapshotCtrl snapCtrl

.. c:function:: ElError ElPseudospecCtrlDefault_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDefault_d( ElPseudospecCtrl_d* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_s( ElPseudospecCtrl_s* ctrl )
.. c:function:: ElError ElPseudospecCtrlDestroy_d( ElPseudospecCtrl_d* ctrl )
