#include "game_manager.hpp"
#include <iostream>

bool GameManager::updateAll(){
  view.update(entMg.getAllViewInfo());
  
  int a;
  std::cin >> a;

  return true;
}
