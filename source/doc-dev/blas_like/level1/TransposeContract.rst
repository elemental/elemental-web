TransposeContract
=================
Perform :math:`B := \sum_i A_i^T` or :math:`B := \sum_i A_i^H`, where the 
summation is performed over the local data of each member of the process team 
that was redundantly assigned entries of :math:`A` but is not redundantly 
assigned entries of :math:`B`.
Thus, in the general case where each column and row of :math:`A` is respectively
distributed over the process sets :math:`U_0 \times U_1` and 
:math:`V_0 \times V_1`, while each column and row of :math:`B` is respectively
distributed over :math:`U_0` and :math:`V_0`, then the result is of the form

.. math::

   B = \sum_{i \in U_1 \times V_1} A_i^T

or

.. math::

   B = \sum_{i \in U_1 \times V_1} A_i^H.

C++ API
-------
.. cpp:function:: void TransposeContract( const AbstractDistMatrix<T>& A, AbstractDistMatrix<T>& B, bool conjugate=false )
.. cpp:function:: void TransposeContract( const AbstractBlockDistMatrix<T>& A, AbstractBlockDistMatrix<T>& B, bool conjugate=false )

C API
-----
**TODO**

Python API
----------
**TODO**
