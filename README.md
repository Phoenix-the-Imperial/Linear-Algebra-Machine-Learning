# Machine Learning
## Description
 A Machine Learning library written in C++. Current Version: ML-0.0.10.
## Version: ML-0.0.10
 The following changes were made:
 1. Implemented a function to solve a system of linear equations given the L and U matrices as arguments.
 2. Re-implemented the inverse of a matrix using LU decomposition (`LU_inverse()`) to only compute the LU decomposition at the beginning and store the matrices for reusing for getting each column instead of recomputing the LU decomposition each time.
 3. Implemented a function called `pseudo_inverse()` for the Moore-Penrose inverse of a matrix.
## Version: ML-0.0.9
 The following changes were made:
 1. Implemented two member functions `set_row()` and `set_col()` for setting rows and columns of a matrix respectively.
 2. Implemented inverse of a matrix by LU decomposition using the Dolittle algorithm.
## Version: ML-0.0.8
 The following changes were made:
 1. Added functions for solving a set of linear equations for upper and lower triangular matrices with back substitution and forward substitution respectively.
 2. Combining the above two functions, named `solve_back_substitution()` and `solve_forward_substitution()`, defined a function called `LU_solve()` for solving a set of linear equations using LU-decomposition. Note that, this LU-decomposition uses the Doolittle algorithm added in Version ML-0.0.4.
## Version: ML-0.0.7
 The following changes were made:
 1. Added vector to matrix conversion.
 2. Added vector matrix multiplication without needing to convert the vector to matrix first.
## Version: ML-0.0.6
 The following changes were made:
 1. Added matrix addition and entry-wise scalar-matrix addition.
 2. Added Hadamard product of matrices.
## Version: ML-0.0.5
 The following changes were made:
 1. Added the functions `zeros()` and `ones()` for creating matrices with only 0 entries and 1 entries respectively.
 2. Added scalar-matrix multiplication.
## Version: ML-0.0.4
 Added LU factorization using the Doolittle algorithm.
## Version: ML-0.0.3
 The following changes were made:
 1. Defined a getter (`get_at()`) for matrix elements that can not mutate the element it is accessing (unlike `at()`).
 2. Implemented a `transpose()` function for matrices.
## Version: ML-0.0.2
 Defined the matrix functions `resize()`, `size()` and a new constructor. Also implemented matrix multiplication.
## Version: ML-0.0.1
 Defined a basic matrix class.
## Version: ML-0.0.0
 Only the rough sketches for the matrix class and vector dot product added.
