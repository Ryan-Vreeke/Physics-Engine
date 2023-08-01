#include "Entity.h"

Entity::Entity(int _size) : size(_size) {
  r = rand();
  g = rand();
  b = rand();

  a = new Matrix();
  v = new Matrix();
  pos = new Matrix();
}
Entity::Entity(int _size, float _x, float _y) : size(_size) {
  r = rand();
  g = rand();
  b = rand();

  a = new Matrix();
  v = new Matrix();
  pos = new Matrix(_x, _y);
}

void Entity::move(Matrix *vector) {
  pos->add(*vector);
}
bool Entity::collision(Entity *other){
  return pos->dist(*other->pos) < size;
}

void Entity::draw(const Cairo::RefPtr<Cairo::Context> &cr) const {
  cr->save();

  // set the drawing color and properties
  cr->set_source_rgb(r, g, b);
  cr->set_line_width(2.0);

  // draw a circle
  cr->arc(pos->x, pos->y, size, 0, 2 * M_PI);
  cr->stroke();

  cr->restore();
}

float Entity::rand() {
  return (float)(std::rand()) / static_cast<float>(RAND_MAX);
}
