#include "glibmm/main.h"
#include "cairomm/context.h"
#include "glibmm/refptr.h"
#include "gtkmm/widget.h"
#include <gtkmm-3.0/gtkmm.h>
#include <vector>
#include "Entity.h"
#include "Matrix.h"

using namespace Glib;
using namespace Gtk;

class Physics{
public:
  static void update(Entity *entity){

  }
};

class MyDrawingArea : public Gtk::DrawingArea {
public:
  int x = 0;
  int y = 0;
  std::vector<Entity*> *objects = new std::vector<Entity*>();

protected:
  bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override {
    Allocation allocation = get_allocation();
    const int width = 10;
    const int height = 10;

    for (auto e : *objects) {
      e->draw(cr);
    }

    return true;
  }

public:
  void update(int _y) {
    for(int i = 0; i < objects->size(); i++){
      objects->at(i)->update();
    }
    queue_draw();
  }

  void add_entity(Entity *e) { 
    objects->push_back(e);
  }
};

int main(int argc, char *argv[]) {
  auto application = Application::create(argc, argv);
  Window window;

  Entity *e1 = new Entity(5, 100, 100);
  Entity *e2 = new Entity(5, 120, 100);
  Entity *e3 = new Entity(5, 140, 100);
  Entity *e4 = new Entity(5, 160, 100);

  window.set_default_size(500, 500);
  MyDrawingArea drawing_area;
  Physics physics;

  drawing_area.add_entity(e1);
  drawing_area.add_entity(e2);
  drawing_area.add_entity(e3);
  drawing_area.add_entity(e4);

  window.add(drawing_area);
  drawing_area.show();

  Glib::signal_timeout().connect(
      [&drawing_area]() {
        drawing_area.update(10);
        return true;
      },
      34);

  Glib::signal_timeout().connect(
      [&drawing_area]() {
        return true;
      },
      1000);
  return application->run(window);
}
