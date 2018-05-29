#pragma once

#include "entity_manager.hpp"
#include "view.hpp"
#include "position.hpp"

class GameManager{
  private:
  const int BASE_ROBOT_NUM = 5;
  const int MAX_ROBOT_NUM = 40;
  const int LEVEL_SCORE = 10;
  EntityManager entMg;
  View view;
  Position fieldSize;
  int level;
  int score;

  public:
  GameManager(int level,Position fieldSize);
  bool updateAll();

};
