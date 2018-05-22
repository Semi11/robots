#pragma once

#include position.hpp

struct ViewInfo{
  public: 
  Position pos;
  ViewInfo viewState;
  ViewInfo(Position pos viewState vs):pos(pos), viewState(vs){}
};
