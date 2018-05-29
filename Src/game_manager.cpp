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
  entMg.update(convertInputData(getChar()), fieldSize);
  score += entMg.checkCollision();

  if(!entMg.existsRobot()){
    score += level * LEVEL_SCORE;
    level++;
    entMg = EntityManager(std::min(level * BASE_ROBOT_NUM, MAX_ROBOT_NUM), fieldSize);
  }

  view.update(entMg.getAllViewInfo(), level, score);

  return entMg.isPlayerAlive();
}

InputData GameManager::convertInputData(char c){
  switch(c){
    case 'q':
    case '7':return UPLEFT;
    case 'w':
    case '8':return UP;
    case 'e':
    case '9':return UPRIGHT;
    case 'a':
    case '4':return LEFT;
    case 's':
    case '5':return CENTER;
    case 'd':
    case '6':return RIGHT;
    case 'z':
    case '1':return DOWNLEFT;
    case 'x':
    case '2':return DOWN;
    case 'c':
    case '3':return DOWNRIGHT;
    case 'r':
    case '0':return WARP;
    default:return ERROR;
  }
}
