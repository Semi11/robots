#include "game_manager.hpp"
#include "position.hpp"

int main(void){
  
  GameManager gm(5, Position(20,15));

  while(gm.updateAll());

  return 0;
}

