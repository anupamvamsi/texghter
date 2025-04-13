#pragma once

#include <iostream>
#include <string>

#include "Creature.hpp"

class Player : public Creature {
 private:
  int m_level{1};

 public:
  Player();
  Player(const std::string& name);

  Player* CreatePlayer();
  int GetLevel();
  void LevelUp();
  bool HasWon();
  void ResetStats();
  void PrintStats();

  ~Player();
};