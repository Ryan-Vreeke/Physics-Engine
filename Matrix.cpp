#include "Matrix.h"

Matrix::Matrix(float _x, float _y) : x(_x), y(_y) {}
Matrix::Matrix() : x(0), y(0) {}

float Matrix::mag() { return sqrt((x * x) + (y * y)); }

void Matrix::scale(float s) {
  x *= s;
  y *= s;
}

float Matrix::dist(Matrix b) {
  return sqrt(((b.get_x() - x) * (b.get_x() - x)) +
              ((b.get_y() - y) * (b.get_y() - y)));
}

float Matrix::dir() { return atan(y / x); }

void Matrix::add(Matrix b) {
  x += b.get_x();
  y += b.get_y();
}

float Matrix::dot(Matrix b) { return (x * b.get_x()) + (y * b.get_y()); }

float Matrix::get_x() { return x; }
float Matrix::get_y() { return y; }
