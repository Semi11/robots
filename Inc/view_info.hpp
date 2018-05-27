#pragma once

#include "position.hpp"
#include "entity_state.hpp"

struct ViewInfo{
  public: 
  Position pos;
  EntityState entityState;
  ViewInfo(Position pos ,EntityState es):pos(pos), entityState(es){}
  ViewInfo(){ViewInfo(Position(0,0), NONE);}
};
