#pragma once

class Position{
  private:
  int x;
  int y;
  
  public:
  Position(int x, int y):x(x),y(y){}
  Position(int pos, Position fieldSize):Position(pos % fieldSize.getX(), pos / fieldSize.getX()){}
  Position():Position(0,0){}
  Position add(int px, int py);
  Position add(Position p);
  int getX(void);
  int getY(void);
  int getLinerPos(int width){return y * width + x;}
};

