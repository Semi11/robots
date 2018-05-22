#pragma once

#include "positon.hpp"
#include "view_state.hpp"

class Entity{
  private:
  Position pos; 
  Position prePos;
  bool live;
  ViewState viewState;
  
  public:
  void move(Position pos);
  void collision();
};
