#include "Body.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Physics {
private:
  Matrix *gravity;
public:
  Physics(){
    gravity = new Matrix(0,9.8);
  }

  void update(std::vector<Body>* objects){
    for(int i = 0; i < objects->size(); i++){
      objects->at(i).add_force(*gravity);
    }
  }
};
