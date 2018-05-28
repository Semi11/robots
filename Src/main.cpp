#include "game_manager.hpp"
#include "position.hpp"

int main(void){
  GameManager gm(1, Position(40,30));

  while(gm.updateAll());

  return 0;
}

