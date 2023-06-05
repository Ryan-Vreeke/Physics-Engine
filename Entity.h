#ifndef ENTITY_H_
#define ENTITY_H_

#include <istream>
#include "cairomm/refptr.h"
#include "glibmm/main.h"
#include "cairomm/context.h"
#include "glibmm/refptr.h"
#include "gtkmm/widget.h"
#include <gtkmm-3.0/gtkmm.h>
#include <bits/stdc++.h>
#include "Matrix.h"
#include <cmath>
#include <cstdlib>

using namespace Glib;
using namespace Gtk;

class Entity {
public:
  float r,g,b;
  int size;
  Matrix *pos;
  Matrix *a;
  Matrix *v;

  float rand();

public:
  Entity(int size);
  Entity(int size,float _x, float _y);
  void update(); 
  void draw(const Cairo::RefPtr<Cairo::Context>& cr) const;
};

#endif
