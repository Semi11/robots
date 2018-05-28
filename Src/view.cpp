#include "view.hpp"

View::View(Position size):size(size){
  
}

void View::update(std::vector<ViewInfo> viewInfoList, int level, int score){
  //画面クリア
  clear();

  //壁表示
  dispStr(Position(0, 0), "+");
  dispStr(Position(size.getX()+WALL_TICK, 0), "+");
  dispStr(Position(0, size.getY()+WALL_TICK), "+");
  dispStr(Position(size.getX()+WALL_TICK, size.getY()+WALL_TICK), "+");

  moveCur(Position(WALL_TICK,0));
  for(int i=0; i<size.getX(); i++)std::cout<< "-";
  moveCur(Position(WALL_TICK,size.getY()+WALL_TICK));
  for(int i=0; i<size.getX(); i++)std::cout<< "-";
  
  for(int i=0; i<size.getY(); i++){
    dispStr(Position(0,i+WALL_TICK), "|");
    dispStr(Position(size.getX()+WALL_TICK,i+WALL_TICK), "|");
  }
  
  //entity表示
  for(auto v: viewInfoList){
    dispStr(v.pos.add(WALL_TICK,WALL_TICK), VIEW_ENTITY_LIST.at(v.entityState));
  }

  moveCur(Position(0,size.getY()+WALL_TICK*2));
  std::cout << "(level:" << level << " score:" << score << "):?";

}
