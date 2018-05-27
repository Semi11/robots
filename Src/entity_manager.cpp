#include <random>
#include <algorithm>
#include "entity_manager.hpp"

EntityManager::EntityManager(int robotNum, Position fieldSize): entityList(robotNum), fieldData(fieldSize.getLinerPos(fieldSize.getX()-1)){
  int linerFieldSize = static_cast<int>(fieldData.size());

  //各エンティティの初期位置を決定
  fieldData.at(0) = PLAYER;
  for(int i=1; i<linerFieldSize; i++){
    if(i < robotNum+1)fieldData.at(i) = ROBOT;  
    else fieldData.at(i) = NONE;
  }

  //シャッフル
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::shuffle(fieldData.begin(), fieldData.end(), engine);
  
  //決定された初期位置からエンティティを作成
  int cnt=0;

  for(int i=0; i<linerFieldSize; i++){
    if(fieldData.at(i) == ROBOT){
       entityList.at(cnt).init(Position(i,fieldSize) , ROBOT);
       cnt++;
    }

    if(fieldData.at(i) == PLAYER) player.init(Position(i,fieldSize), PLAYER);

    if(cnt > static_cast<int>(entityList.size())) throw 1;
  }
  
  
}

std::vector<ViewInfo> EntityManager::getAllViewInfo(){
  int size = static_cast<int>(entityList.size()) + 1;
  std::vector<ViewInfo> viewInfoList(size);

  viewInfoList.at(0) = player.getViewInfo();
  for(int i=1;i<size;i++){
    viewInfoList.at(i) = entityList.at(i-1).getViewInfo();
  }

  return viewInfoList;
}

void EntityManager::update(char input, Position fieldSize){
  Position targetPos;
  Position speed = Position(1,1);
  Position prePlayerPos = player.getPos();
  int width = fieldSize.getX();

  //プレイヤーの移動
  switch(input){
    case 'q':targetPos = Position(-1,-1);break;
    case 'w':targetPos = Position(0,-1);break;
    case 'e':targetPos = Position(1,-1);break;
    case 'a':targetPos = Position(-1,0);break;
    case 's':targetPos = Position(0,0);break;
    case 'd':targetPos = Position(1,0);break;
    case 'z':targetPos = Position(-1,1);break;
    case 'x':targetPos = Position(0,1);break;
    case 'c':targetPos = Position(1,1);break;
    default:return;
  }

  targetPos.add(player.getPos());
  if(!player.move(targetPos, speed, fieldSize)) return;
  
  if(fieldData.at(player.getPos().getLinerPos(width)) != NONE) {//プレイヤーは何もないところにのみ移動可
    player.move(prePlayerPos, fieldSize);
    return;
  }
  fieldData.at(prePlayerPos.getLinerPos(width)) = NONE;
  fieldData.at(player.getPos().getLinerPos(width)) = PLAYER;

  //ロボットの移動
  for(auto &e: entityList){
    if(e.isAlive()){
      fieldData.at(e.getPos().getLinerPos(width)) = NONE;
      e.move(player.getPos(), speed, fieldSize);
      fieldData.at(e.getPos().getLinerPos(width)) = e.getState();
    }
  }
}
