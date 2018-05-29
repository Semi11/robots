#pragma once

#include <vector>
#include "entity.hpp"
#include "view_info.hpp"
#include "input_data.hpp"

class EntityManager{
  private:
  std::vector<Entity> entityList; 
  std::vector<EntityState> fieldData;
  Entity player;

  public:
  EntityManager(int robotNum, Position fieldSize);
  std::vector<Entity> getAllEntity();
  std::vector<ViewInfo> getAllViewInfo();
  void update(InputData input, Position fieldSize);
  int checkCollision();
  bool isPlayerAlive();
  bool existsRobot();
  Position getRandomPos(Position fieldSize);
};
