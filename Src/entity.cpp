#include "entity.hpp"

void Entity::init(Position p, EntityState s){
  pos = p;
  state = s;
  live = true;
}
  
ViewInfo Entity::getViewInfo(){
  return ViewInfo(pos, state);
}

bool Entity::move(Position target, Position speed, Position fieldSize){
  if(!live)return false; 
  Position pre = pos;

  if(pos.getX() < target.getX()) pos.add(speed.getX(), 0);
  else if(pos.getX() > target.getX()) pos.add(-speed.getX(), 0);

  if(pos.getY() < target.getY()) pos.add(0, speed.getY());
  else if(pos.getY() > target.getY()) pos.add(0, -speed.getY());
  
  if(pos.getX() < 0 || pos.getX() >= fieldSize.getX() || pos.getY() < 0 || pos.getY() >= fieldSize.getY()){
    pos = pre;
    return false;
  }

  return true;
}

Position Entity::getPos(){
  return pos;
}
