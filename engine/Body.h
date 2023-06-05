#ifndef BODY_H
#define BODY_H


#include "Matrix.h"

class Body {

public:
  Matrix *pos;
  Matrix *v;
  Matrix *a;

public:
  float m;

public:
  Body();
  Body(float x, float y, float _m);
  void add_force(Matrix f);
  float dir();
  Matrix get_pos();
  Matrix get_v();
  Matrix get_a();
};

#endif
