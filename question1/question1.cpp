#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "qr_decomp.h"

#define N 4

int main () {
  Matrice A, Q, R;
  Vector u, q;

  A.allocMatrice(N);
  Q.allocMatrice(N);
  R.allocMatrice(N);
  u.allocVector(N);
  q.allocVector(N);

  for (unsigned int j = 0; j < A.lenght; j++) {
    for (unsigned int i = 0; i < A.lenght; i++) {
      scanf("%lf", (A.col[i] + j));
    }
  }
  



  return 0;
}
