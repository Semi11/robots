#pragma once

#include <random>

//静的クラス
class RandomGenerator{
  private:
  RandomGenerator() = delete;
  
  public:
  static std::mt19937 & get(){
    static std::random_device rnd;
    static std::mt19937 mt(rnd());
    return mt;
  }
};
