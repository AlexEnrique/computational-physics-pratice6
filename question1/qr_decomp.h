void initializeA(double ***A, unsigned int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%lf", &((*A)[i][j]));
    }
  }
}

// Cria as matrizes Q e U (vetores qi e ui)
void setQU(double **A, double ***Q, double ***U, unsigned int N) {
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      (*U)[k][i] = A[k][i];
      for (int j = 0; j < i; j++) {
        (*U)[k][i] -= dotProd((*Q), j, A, i, N) * (*Q)[k][j];
      }
    }
    for (int m = 0; m < N; m++) {
      (*Q)[m][i] = (*U)[m][i] / norm(*U, i, N);
    }
  }
}

/* Cria a matriz R */
void setR(double **A, double **Q, double ***R, double **U, unsigned int N) {
  // Diagonal
  for (int i = 0; i < N; i++) {
    (*R)[i][i] = norm(U, i, N);
  }

  // acima da diagonal
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      (*R)[i][j] = dotProd(Q, i, A, j, N);
    }
  }
}
