#pragma once

#include <vector>
#include "entity.hpp"
#include "view_info.hpp"

class EntityManager{
  private:
  std::vector<Entity> entityList; 
  std::vector<EntityState> fieldData;
  Entity player;

  public:
  EntityManager(int robotNum, Position fieldSize);
  std::vector<Entity> getAllEntity();
  std::vector<ViewInfo> getAllViewInfo();
  void update(char input, Position fieldSize);
  void checkCollision();
};
