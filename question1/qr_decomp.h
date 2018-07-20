#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdexcept>

class Vector {
  public:
    unsigned int lenght;
    double *pos;
    Vector(); // creator
    void allocVector(unsigned int _lenght);
    double norm();
    double dotProduct(const Vector otherVec);

    Vector operator *(double x) {
      Vector newArr;
      newArr.allocVector(lenght);

      for (unsigned int i = 0; i < lenght; i++) {
        newArr.pos[i] = x*pos[i];
      }

      return newArr;
    }

};
Vector::Vector() { } // creator

void Vector::allocVector(unsigned int _lenght) {
  lenght = _lenght;
  pos = (double*)malloc(lenght * sizeof(*pos));
}

double Vector::norm() {
  double N = 0;

  for (unsigned int i = 0; i < lenght; i++) {
    N += pow(pos[i], 2);
  }

  return N;
}

double Vector::dotProduct(const Vector otherVec) {
  if (otherVec.lenght != lenght) {
    throw std::invalid_argument("Error: vectors must be the same lenght");
  }

  double S = 0;
  for (unsigned int i = 0; i < lenght; i++) {
    S += pos[i] * otherVec.pos[i];
  }

  return S;
}

class Matrice {
  public:
    unsigned int lenght;
    double **col;
    Matrice();
    void allocMatrice(unsigned int _lenght);
};
Matrice::Matrice() { }

void Matrice::allocMatrice(unsigned int _lenght) {
  lenght = _lenght;

  for (unsigned int i = 0; i < lenght; i++) {
    col = (double**)malloc(lenght * sizeof(**col));
  }

  for (unsigned int i = 0; i < lenght; i++) {
    col[i] = (double*)malloc(lenght * sizeof(**col));
  }
}
