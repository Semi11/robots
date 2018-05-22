#pragma once

#include "position.hpp"
#include "view_state.hpp"

class Entity{
  private:
  Position pos; 
  bool live;
  ViewState viewState;
  
  public:
  Entity(){};
  void move(Position pos);
  void collision();
};
