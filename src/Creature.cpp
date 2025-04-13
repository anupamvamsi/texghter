#include "Creature.hpp"

#include <iostream>
#include <string>

Creature::Creature() 
    : m_name{""}, m_symbol{' '}, m_health{0}, m_damage{0}, m_gold{0} {}

Creature::Creature(const std::string& name, char symbol, int health, int damage,
                   int gold)
    : m_name{name},
      m_symbol{symbol},
      m_health{health},
      m_damage{damage},
      m_gold{gold} {}

// Getters
const std::string& Creature::GetName() const { return m_name; }
char Creature::GetSymbol() { return m_symbol; }
int Creature::GetHealth() { return m_health; }
int Creature::GetDamage() { return m_damage; }
int Creature::GetGold() { return m_gold; }

void Creature::ReduceHealth(int reduce_amount) { m_health -= reduce_amount; }

bool Creature::IsDead() {
  if (m_health < 1) {
    return true;
  }

  return false;
}

void Creature::AddGold(int add_amount) { m_gold += add_amount; }

Creature::~Creature() {}