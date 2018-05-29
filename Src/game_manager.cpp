#include "game_manager.hpp"
#include <iostream>
#include <algorithm>
extern "C"{
#include "../sample/getchar.c"
}

bool GameManager::updateAll(){
  view.update(entMg.getAllViewInfo(), level, score);
  entMg.update(getChar(), fieldSize);
  score += entMg.checkCollision();

  if(!entMg.existsRobot()){
    score += level * LEVEL_SCORE;
    level++;
    entMg = EntityManager(std::min(level * BASE_ROBOT_NUM, MAX_ROBOT_NUM), fieldSize);
  }

  return entMg.isPlayerAlive();
}
