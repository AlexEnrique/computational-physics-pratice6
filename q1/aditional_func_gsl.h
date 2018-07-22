gsl_matrix *gsl_squareMatProd(gsl_matrix *A, gsl_matrix *B, unsigned int n) {
  gsl_matrix *C = gsl_matrix_alloc(n, n);

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      double S = 0;
      for (unsigned int r = 0; r < n; r++) {
        S += gsl_matrix_get(A, i, r) * gsl_matrix_get(B, r, j);
      }
      gsl_matrix_set(C, i, j, S);
    }
  }

  return C;
}

short gsl_checkOffDiagonal(gsl_matrix *A, unsigned int n, double eps) {
  for (unsigned int i = 0; i < n; i++)
    for (unsigned int j = 0; j < n; j++)
      if ( i != j && fabs(gsl_matrix_get(A, i, j)) > eps )
        return 0;

  return 1;
}

void gsl_printSquareMatrix(gsl_matrix *V, unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (j != 0 && gsl_matrix_get(V, i, j) > 0)
        printf(" ");
      printf("%lf ", gsl_matrix_get(V, i, j));
    }
    printf("\n");
  }

  printf("\n");
}
