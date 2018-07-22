#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

void allocSquareMatrix(double ***A, unsigned int n) {
  (*A) = calloc(n, sizeof(***A));
  for (unsigned int i = 0; i < n; i++) {
    (*A)[i] = calloc(n, sizeof(***A));
  }
}

double dotProd(double **U, int j, double **V, int k, unsigned int n) {
  double S = 0;

  for (unsigned int i = 0; i < n; i++) {
    S += U[i][j] * V[i][k];
  }

  return S;
}

double norm(double **V, int i, unsigned int n) {
  return sqrt(dotProd(V, i, V, i, n));
}

void printMatrix(double **M, unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (j != 0 && M[i][j] > 0)
        printf(" ");
      printf("%lf ", M[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

double **squareMatriceProd(double **A, double **B, unsigned int n) {
  double **C;
  allocSquareMatrix(&C, n);

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      double S = 0;
      for (unsigned int r = 0; r < n; r++) {
        S += A[i][r] * B[r][j];
      }
      C[i][j] = S;
    }
  }

  return C;
}

double **identity(unsigned int n) {
  double **M;
  allocSquareMatrix(&M, n);

  for (unsigned int i = 0; i < n; i++) {
    M[i][i] = 1.0;
  }

  return M;
}

short checkOffDiagonal(double **A, unsigned int n, double eps) {
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if ( i != j && fabs(A[i][j]) > eps )
        return 0;

  return 1;
}

double **transpose(double **A, unsigned int n) {
  double **C;
  allocSquareMatrix(&C, n);

  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      C[i][j] = A[j][i];

  return C;
}
