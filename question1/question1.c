#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

#include "func.h"
#include "qr_decomp.h"

#define N 4
#define EPS 1E-6

int main () {
  double **A, **Q, **U, **R, **V;
  short reach; // boolean type

  allocSquareMatrix(&A, N);
  allocSquareMatrix(&Q, N);
  allocSquareMatrix(&U, N);
  allocSquareMatrix(&R, N);
  allocSquareMatrix(&V, N);

  // Lê a matriz A
  initializeA(&A, N);

  // V = I (inicialmente)
  V = identity(N);

  setQU(A, &Q, &U, N);
  setR(A, Q, &R, U, N);

  printf("Matrix Q:\n");
  printMatrix(Q, N);

  printf("Matrix R:\n");
  printMatrix(R, N);

  do {
    // QR decomposition
    setQU(A, &Q, &U, N);
    setR(A, Q, &R, U, N);
    free(U);

    // A = RQ; V = VQ (V == Q1*Q2...*Qn)
    A = squareMatriceProd(R, Q, N);
    V = squareMatriceProd(V, Q, N);

    reach = checkOffDiagonal(A, N, EPS);
  } while (!reach);

  // Eigenval
  printf("Eigenvalues' matrice:\n");
  printMatrix(A, N);

  printf("Eigenvectors' matrix: \n");
  // Eigenvec
  printMatrix(V, N);

  return 0;
}
