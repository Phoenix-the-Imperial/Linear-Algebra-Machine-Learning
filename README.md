# Machine Learning

## Description

 A Linear Algebra and Machine Learning library written in C++. Current Version: ML-0.0.15.
 Name: Rishav Chakraborty, Roll No.: 21EE30034, IIT Kharagpur.

## Installation Guidlines

 1. Clone the Git repository inside the target folder as follows:
 ```shell
 git clone https://github.com/Phoenix-the-Imperial/Linear-Algebra-Machine-Learning.git
 ```
 2. Build the test executable by running
 ```shell
 make
 ```
 3. The test executable can be executed by running
 ```shell
 ./bin/test
 ```

## Check-list of Upcoming Features

 - [x] Add algorithms for Hadamard division.
 - [x] Add exception handling.
 - [ ] Add functionality for building the library and release.
 - [ ] Add some statistical functions.
 - [ ] Add Gaussian elimination with scaled partial pivoting.
 - [ ] Add stable algorithm for LU decomposition.
 - [ ] Add algorithms for finding the QR decomposition.
 - [ ] Add algorithms for finding eigenvalues and eigenvectors.
 - [ ] Add algorithms for diagonalization.
 - [ ] Add algorithms for finding the singular value decomposition.
 - [ ] Add a function implementing the Gram-Schmidt orthogonalization procedure for finite number of vectors.
 - [ ] Add a custom exception class.
 - [ ] Replace `size_t` with better/variable types.
 - [ ] Reorganize the codes into header files.

# Version History

## Version: ML-0.0.15

 Created a (possibly buggy) function to compute the spectral radius of a matrix.

## Version: ML-0.0.14

 Created a function for the entry-wise matrix $L_{p, q}$ norm along with an overload for the case when $p = q$.

## Version: ML-0.0.13

 Created subtraction operations for matrix-matrix and matrix-scaler cases. Added very basic exception handling to all of the necessary cases currently present.

## Version: ML-0.0.12

 Created a function for Hadamard division of matrices.

## Version: ML-0.0.11

 Created operators for matrix multiplication, matrix addition, matrix-scalar multiplication, matrix-scalar addition and matrix-vector multiplicatiion.

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
