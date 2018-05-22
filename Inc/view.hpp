#pragma once

class View{
  private:
  Position size;

  public:
  View(Position size):size(size){}
  void update();
};
