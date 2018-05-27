#pragma once

#include "position.hpp"
#include "entity_state.hpp"
#include "view_info.hpp"

class Entity{
  private:
  Position pos; 
  bool live;
  EntityState state;
  
  public:
  Entity(Position pos, EntityState s):pos(pos),live(true),state(s){}
  Entity(EntityState s):Entity(Position(), s){}
  Entity():Entity(NONE){}
  void init(Position pos, EntityState s);
  bool move(Position target, Position fieldSize);
  bool move(Position target, Position speed, Position fieldSize);
  void collision();
  ViewInfo getViewInfo();
  Position getPos();
  EntityState getState();
  bool isAlive();
};
