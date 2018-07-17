#include <stdio.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include "functions.h"

#define NUM_ATOMS 6
#define BETA_0 -2.5 // eV

double h(int i);
double k(int i);

int main () {
  const size_t n = NUM_ATOMS;
  gsl_eigen_symmv_workspace *w;
  gsl_matrix *M, *evec;
  gsl_vector *alpha, *beta, *energies;

  w = gsl_eigen_symmv_alloc(n);
  M = gsl_matrix_calloc(n, n); // ..._calloc() aloca os espaços atribuindo valor '0'
  evec = gsl_matrix_alloc(n, n);
  energies = gsl_vector_alloc(n);
  alpha = gsl_vector_alloc(n);
  beta = gsl_vector_alloc(n);

  // Inicializando alpha
  for (unsigned int i = 0; i < n; i++) {
    gsl_vector_set(alpha, i, h(i)*BETA_0);
  }

  /* Existe um isomorfismo entre os elementos beta_{i, i+1} de M e o
   * espaço das matrizes colunas de ordem n-1. Assim, utilizamos um
   * array para beta, por questão de economaia e organização. Após
   * a inicialização de M, beta (e alpha) são desalocados.
   */
  // Inicializando beta
  for (unsigned int i = 0; i < n; i++) {
    gsl_vector_set(beta, i, k(i)*BETA_0);
  }

  // Inicializando M
  for (unsigned int i = 0; i < n; i++) {
    gsl_matrix_set(M, i, i, gsl_vector_get(alpha, i));
  }
  gsl_vector_free(alpha); // libera o espaço da memória de alpha

  for (unsigned int i = 0; i+1 < n; i++) {
    gsl_matrix_set(M, i, i+1, gsl_vector_get(beta, i));
    gsl_matrix_set(M, i+1, i, gsl_vector_get(beta, i));
  }
  gsl_vector_free(beta); // libera o espaço da memória de beta

  // Calcula os autovalores (energies) e autovetores (evec)
  gsl_eigen_symmv(M, energies, evec, w);
  // Ordena os autovalores (e os respectivos autovetores)
  // GSL_EIGEN_SORT_VAL_ASC == ascending order in numerical value
  gsl_eigen_symmv_sort(energies, evec, GSL_EIGEN_SORT_VAL_ASC);

  printf("=================================================================\n");
  // Imprime as autoenergias
  printf("Auto-energias: \n");
  for (unsigned int i = 0; i < n; i++) {
    double Energy = gsl_vector_get(energies, i);
    printf("|E[%d] ", i+1);
    if (Energy > 0)
      printf(" ");
    printf("%1.3lf eV|\n", Energy);
  }
  printf("\n");

  // Imprime os autovetores - cada coluna corresponde a um autovetor
  printf("Autovetores:\n");
  for (unsigned int i = 0; i < n; i++) {
    printf("[");
    for (unsigned j = 0; j < n; j++) {
      double evec_ij = gsl_matrix_get(evec, i, j);
      if (j != 0 && evec_ij > 0)
        printf(" ");
      printf("%lf", evec_ij);
      if (j != n-1) {
        printf(", ");
      }
    }
    printf("]\n");
  }
  printf("=================================================================\n");

  gsl_eigen_symmv_free(w);
  gsl_matrix_free(M);
  gsl_matrix_free(evec);
  gsl_vector_free(energies);
  return 0;
}
