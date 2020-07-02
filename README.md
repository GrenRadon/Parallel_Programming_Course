# IntroPP2111628

** Institution's name: ** Universidad Industrial de Santander
** Student: ** Julian Eduardo Villamizar Peña
** E-mail: ** julianeduardovillamizarpena@outlook.com

## Problem description:

* Matrix-Matrix Multiplication Timings
MXM, a C program which sets up a matrix-matrix multiplication problem A = B * C, and carries it out using it

	- Nested FOR I, J, K loops;
	- Nested FOR I, K, J loops;
	- Nested FOR J, I, K loops;
	- Nested FOR J, K, I loops;
	- Nested FOR K, I, J loops;
	- Nested FOR K, J, I loops;
	- the MATMUL FORTRAN90 intrinsic function;

The user is allowed to specify N1, N2, and N3, which define the matrix sizes. 

Usage:
mxm n1 n2 n3

where:

- n1 is the number of rows in B.
- n2 is the number of columns in B and rows in C.
- n3 is the number of columns in C;

The scope to achieved in this project was to implement a parallelized version of the previous explained C code by using OpenMP directives. 
