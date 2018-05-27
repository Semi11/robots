#include "game_manager.hpp"
#include <iostream>
extern "C"{
#include "../sample/getchar.c"
}

bool GameManager::updateAll(){
  entMg.update(getChar(), fieldSize);
  view.update(entMg.getAllViewInfo());
  return true;
}
