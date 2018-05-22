#pragma once

#include <vector>
#include "entity.hpp"
#include "view_info.hpp"

class EntityManager{
  private:
  std::vector<Entity> entityList; 

  public:
  EntityManager(int entityNum):entityList(entityNum){}
  std::vector<Entity> getAllEntity();
  std::vector<ViewInfo> getAllViewInfo();
  void update();
};
