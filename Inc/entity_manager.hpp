#pragma once

#include <vector>
#include "entity.hpp"

class EntityManager{
  private:
  std::vector<Entity> entityList; 

  public:
  vector<Entity> getAllEntity();
  vector<ViewInfo> getAllViewInfo();
  void update();
};
