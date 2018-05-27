#include "position.hpp"

Position Position::add(int px, int py){
  x += px;
  y += py;
  return Position(x,y);
}

Position Position::add(Position p){
  return add(p.getX(), p.getY());
}

int Position::getX(void){
  return x;
}

int Position::getY(void){
  return y;
}
