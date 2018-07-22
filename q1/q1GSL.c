#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>

#include "func.h"
#include "aditional_func_gsl.h"

#define N 4
#define EPS 1E-6

int main () {
  short reach;
  gsl_matrix *A, *Q, *R, *V;
  gsl_vector *tau;
  gsl_vector_complex *eval = gsl_vector_complex_alloc(N);
  gsl_eigen_nonsymm_workspace *w = gsl_eigen_nonsymm_alloc(N);
  A = gsl_matrix_alloc(N, N);
  Q = gsl_matrix_alloc(N, N);
  R = gsl_matrix_alloc(N, N);
  V = gsl_matrix_alloc(N, N);
  gsl_matrix_set_identity(V);
  tau = gsl_vector_alloc(N);

  // Lê a matriz A
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double x;
      scanf("%lf", &x);
      gsl_matrix_set(A, i, j, x);
    }
  }

  // via schur decomp
  gsl_eigen_nonsymm(A, eval, w);

  printf("Via Schur decomposition: \n");
  for (unsigned int i = 0; i < N; i++) {
    printf("Eigenvalue %d: %.2lf\n", i, gsl_vector_complex_get(eval, i));
  }

  // via QG


  do {
    gsl_linalg_QR_decomp(A, tau);
    gsl_linalg_QR_unpack(A, tau, Q, R);

    A = gsl_squareMatProd(R, Q, N);
    V = gsl_squareMatProd(V, Q, N);

    reach = gsl_checkOffDiagonal(A, N, EPS);
  } while (!reach);

  printf("\n\nVia QR\n");
  for (unsigned int i = 0; i < N; i++) {
    printf("Eigenvalue %d: %lf\n", i+1, gsl_matrix_get(A, i, i));
  }

  printf("\nEigenvectors\n");
  gsl_printSquareMatrix(V, N);

  gsl_matrix_free(A);
  gsl_matrix_free(Q);
  gsl_matrix_free(R);
  gsl_matrix_free(V);
  gsl_vector_free(tau);
  gsl_vector_complex_free(eval);

  return 0;
}
