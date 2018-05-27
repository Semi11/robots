#pragma once

#include "entity_manager.hpp"
#include "view.hpp"
#include "position.hpp"

class GameManager{
  private:
  EntityManager entMg;
  View view;

  public:
  GameManager(int entNum ,Position fieldSize):entMg(entNum, fieldSize), view(fieldSize){}
  bool updateAll();

};
