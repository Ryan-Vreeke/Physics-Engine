#include "Body.h"

Body::Body() : m(1) {
  pos = new Matrix(0, 0);
  v = new Matrix(0, 0);
  a = new Matrix(0, 0);
}
Body::Body(float x, float y, float _m) : m(_m) {
  pos = new Matrix(x, y);
  v = new Matrix(0, 0);
  a = new Matrix(0, 0);
}

void Body::add_force(Matrix f) { a->add(f); }
float Body::dir() { return v->dir(); }
Matrix Body::get_pos() { return *pos; }
Matrix Body::get_v() { return *v; }
Matrix Body::get_a() { return *a; }
