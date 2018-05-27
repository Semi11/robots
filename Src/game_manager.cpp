#include "game_manager.hpp"
#include <iostream>
extern "C"{
#include "../sample/getchar.c"
}

bool GameManager::updateAll(){
  view.update(entMg.getAllViewInfo());
  entMg.update(getChar(), fieldSize);
  entMg.checkCollision();
  return true;
}
