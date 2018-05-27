#include "position.hpp"

Position Position::add(int px, int py){
  x += px;
  y += py;
  return Position(x,y);
}

int Position::getX(void){
  return x;
}

int Position::getY(void){
  return y;
}
