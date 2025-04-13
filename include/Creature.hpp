#pragma once

#include <iostream>
#include <string>

class Creature {
 protected:
  std::string m_name;
  char m_symbol;
  int m_health;
  int m_damage;
  int m_gold;

 public:
  Creature();
  Creature(const std::string& name, char symbol, int health, int damage,
           int gold);

  // Getters
  const std::string& GetName() const;
  char GetSymbol();
  int GetHealth();
  int GetDamage();
  int GetGold();

  void ReduceHealth(int reduce_amount);

  bool IsDead();

  void AddGold(int add_amount);

  ~Creature();
};