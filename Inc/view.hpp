#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "position.hpp"
#include "view_info.hpp"

class View{
  private:
  Position size;
  const int WALL_TICK=1;
  const std::vector<std::string> VIEW_ENTITY_LIST = {
    " ", "@", "+", "*" 
  };

  public:
  View(Position size);
  void update(std::vector<ViewInfo> viewInfoList);
  void clear(){std::cout<< "\033[2J";}
  void moveCur(Position pos){
    std::cout<< "\033[" << pos.getY()+1 << ";" << pos.getX()+1 << "H"; //端末の原点は(1,1)のため補正をかける
  }
  void dispStr(Position pos, std::string str){
    moveCur(pos);
    std::cout<< str;
  }
};

