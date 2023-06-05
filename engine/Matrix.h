#ifndef MATRIX_H_
#define MATRIX_H_

#include <cmath>

class Matrix {
public:
  float x;
  float y;

public:
  Matrix(float x, float y);
  Matrix();
  

  float get_x();
  float get_y();

  float mag();
  float dist(Matrix b);
  float dir();
  float dot(Matrix b);
  void scale(float s);
  void add(Matrix b);
};

#endif
