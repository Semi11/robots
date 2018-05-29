#include <algorithm>
#include "entity_manager.hpp"
#include "random_generator.hpp"

EntityManager::EntityManager(int robotNum, Position fieldSize): entityList(robotNum), fieldData(fieldSize.getX() * fieldSize.getY()){
  int linerFieldSize = static_cast<int>(fieldData.size());

  //各エンティティの初期位置を決定
  fieldData.at(0) = PLAYER;
  for(int i=1; i<linerFieldSize; i++){
    if(i < robotNum+1)fieldData.at(i) = ROBOT;  
    else fieldData.at(i) = NONE;
  }

  //シャッフル
  std::shuffle(fieldData.begin(), fieldData.end(), RandomGenerator::get());
  
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

void EntityManager::update(InputData input, Position fieldSize){
  Position targetPos = Position(0,0);
  Position speed = Position(1,1);
  Position prePlayerPos = player.getPos();
  int width = fieldSize.getX();

  //プレイヤーの移動
  if(input != WARP){
    switch(input){
      case    UPLEFT: targetPos = Position(-1,-1);break;
      case        UP: targetPos = Position(0,-1);break;
      case   UPRIGHT: targetPos = Position(1,-1);break;
      case      LEFT: targetPos = Position(-1,0);break;
      case    CENTER: targetPos = Position(0,0);break;
      case     RIGHT: targetPos = Position(1,0);break;
      case  DOWNLEFT: targetPos = Position(-1,1);break;
      case      DOWN: targetPos = Position(0,1);break;
      case DOWNRIGHT: targetPos = Position(1,1);break;
      default:return;
    }

    targetPos.add(player.getPos());
    if(!player.move(targetPos, speed, fieldSize)) return;


    if(fieldData.at(player.getPos().getLinerPos(width)) == ROBOT || 
        fieldData.at(player.getPos().getLinerPos(width)) == SCRAP) {//プレイヤーは何もないところにのみ移動可
      player.move(prePlayerPos, fieldSize);
      return;
    }

  }else{
    player.move(getRandomPos(fieldData, fieldSize), fieldSize);
  }

  fieldData.at(prePlayerPos.getLinerPos(width)) = NONE;
  fieldData.at(player.getPos().getLinerPos(width)) = PLAYER;

  //ロボットの移動
  speed = Position(1,1);
  for(auto &e: entityList){
    if(e.isAlive()){
      fieldData.at(e.getPos().getLinerPos(width)) = NONE;
      e.move(player.getPos(), speed, fieldSize);
      fieldData.at(e.getPos().getLinerPos(width)) = e.getState();
    }
  }
}

int EntityManager::checkCollision(){
  int px = player.getPos().getX();
  int py = player.getPos().getY();
  int entNum = static_cast<int>(entityList.size());
  int score = 0;

  for(auto e: entityList){
    if(px == e.getPos().getX() && py == e.getPos().getY()){
      player.collision();
    }
  }

  for(int i=0;i<entNum-1;i++){
    int ex = entityList.at(i).getPos().getX();
    int ey = entityList.at(i).getPos().getY();
    for(int j=i+1;j<entNum;j++){
      if(ex == entityList.at(j).getPos().getX() && ey == entityList.at(j).getPos().getY()){
        if(entityList.at(i).getState() == ROBOT) score++;
        if(entityList.at(j).getState() == ROBOT) score++;
        entityList.at(i).collision();
        entityList.at(j).collision();
      }
    }
  }

  return score;
}

bool EntityManager::isPlayerAlive(){
  return player.isAlive();
}

bool EntityManager::existsRobot(){
  for(auto e: entityList){
    if(e.getState() == ROBOT) return true;
  }
  return false;
}

//フィールドの何もない座標をランダムで取得
Position EntityManager::getRandomPos(std::vector<EntityState> bs, Position fs){
  std::vector<int> nonePosList;
  
  for(int i=0; i<static_cast<int>(bs.size()); i++){
    if(bs.at(i) == NONE) nonePosList.push_back(i);  
  }
  
  std::uniform_int_distribution<> ranNum(0, static_cast<int>(nonePosList.size())-1);
  return Position(nonePosList.at(ranNum(RandomGenerator::get())), fs);
}
