DistMatrix
==========
The :cpp:class:`DistMatrix\<scalarType=double,colDist=MC,rowDist=MR,wrapType=ELEMENT>` class, where partial specializations to `wrapType=ELEMENT` derive from
:cpp:class:`ElementalMatrix\<scalarType>`, and partial specializations to
`wrapType=BLOCK` derive from :cpp:class:`BlockMatrix\<scalarType>`.
In each case, there are thirteen different legal `(colDist,rowDist)` 
distribution pairs; each is a sensical pairing of one of the following 
applied to the columns of the matrix, and one applied to the rows of the matrix:

-  `CIRC` : Only give the data to a single process
-  `STAR` : Give the data to every process
-  `MC` : Distribute round-robin within each column of the 2D process grid (*M* atrix *C* olumn)
-  `MR`: Distribute round-robin within each row of the 2D process grid (*M* atrix *R* ow)
-  `VC`: Distribute round-robin within a column-major ordering of the entire 2D process grid (*V* ector *C* olumn)
-  `VR`: Distribute round-robin within a row-major ordering of the entire 2D process grid (*V* ector *R* ow)
-  `MD`: Distribute round-robin over a diagonal of the tiling of the 2D process grid (*M* atrix *D* iagonal)

The valid pairings are:

+---------+---------+---------+---------+-----------+---------------+-----------+
| ColDist | RowDist | ColComm | RowComm | DistComm  | RedundantComm | CrossComm |
+=========+=========+=========+=========+===========+===============+===========+
| CIRC    | CIRC    | self    | self    | self      | self          | VC        |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MC      | MR      | MC      | MR      | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MC      | STAR    | MC      | self    | MC        | MR            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MD      | STAR    | MD      | self    | MD        | self          | MDPerp    |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MR      | MC      | MR      | MC      | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| MR      | STAR    | MR      | self    | MR        | MC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MC      | self    | MC      | MC        | MR            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MD      | self    | MD      | MD        | self          | MDPerp    |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | MR      | self    | MR      | MR        | MC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | STAR    | self    | self    | self      | VC            | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | VC      | self    | VC      | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| STAR    | VR      | self    | VR      | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| VC      | STAR    | VC      | self    | VC        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+
| VR      | STAR    | VR      | self    | VR        | self          | self      |
+---------+---------+---------+---------+-----------+---------------+-----------+

where `DistComm` refers to the communicator that the entire matrix (rather than
just the rows or columns) is distributed over. When the matrix is distributed
over a communicator which only involves only a subset of the processes, it is
possible to either assign the data to just that subset or redundantly store
the entire matrix on each such subset of processes (e.g., within each row of a
2D arrangement of the set of processes). The `RedundantComm` refers to the
communicator where each member process stores the same information, and the
`CrossComm` is the communicator where only a single process (the *root*) is
assigned any data.

To make this discussion more precise, each valid matrix distribution for
`DistMatrix` logically arranges the set of `p` processes of the `r` by `c`
process grid into a 4D mesh: `ColComm` x `RowComm` x `RedundantComm` x `CrossComm`, where `DistComm` is equal to `ColComm` x `RowComm`.
