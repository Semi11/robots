#pragma once

#include "position.hpp"
#include "view_state.hpp"

struct ViewInfo{
  public: 
  Position pos;
  ViewState viewState;
  ViewInfo(Position pos ,ViewState vs):pos(pos), viewState(vs){}
};
