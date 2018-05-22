#pragma once

class Position{
  private:
  int x;
  int y;
  
  public:
  Position(int x, int y):x(x),y(y){}
  Position():x(0),y(0){}
  void set(int x, int y);
  void set(Position Pos);
  void getX(void);
  void getY(void);
};

