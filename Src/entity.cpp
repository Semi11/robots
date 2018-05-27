#include "entity.hpp"

void Entity::init(Position p, EntityState s){
  pos = p;
  state = s;
  live = true;
}
  
ViewInfo Entity::getViewInfo(){
  return ViewInfo(pos, state);
}
