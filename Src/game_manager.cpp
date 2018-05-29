#include "game_manager.hpp"
#include <iostream>
#include <algorithm>
extern "C"{
#include "../sample/getchar.c"
}

GameManager::GameManager(int level,Position fieldSize):entMg(level * BASE_ROBOT_NUM, fieldSize), view(fieldSize),fieldSize(fieldSize), level(level), score(0){
  //初期描画
  view.update(entMg.getAllViewInfo(), level, score);
}

bool GameManager::updateAll(){
  entMg.update(getChar(), fieldSize);
  score += entMg.checkCollision();

  if(!entMg.existsRobot()){
    score += level * LEVEL_SCORE;
    level++;
    entMg = EntityManager(std::min(level * BASE_ROBOT_NUM, MAX_ROBOT_NUM), fieldSize);
  }

  view.update(entMg.getAllViewInfo(), level, score);

  return entMg.isPlayerAlive();
}
