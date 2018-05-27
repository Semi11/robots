#pragma once

#include "entity_manager.hpp"
#include "view.hpp"
#include "position.hpp"

class GameManager{
  private:
  EntityManager entMg;
  View view;
  Position fieldSize;

  public:
  GameManager(int entNum ,Position fieldSize):entMg(entNum, fieldSize), view(fieldSize),fieldSize(fieldSize){}
  bool updateAll();

};
