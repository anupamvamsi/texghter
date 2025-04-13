#pragma once

#include "Creature.hpp"

class Monster : public Creature {
 public:
  enum class Type {  //
    Dragon,
    Orc,
    Slime,
    Leprechaun,
    Snagli,
    Cockroach,
    Pigeon,
    max_types
  };

  Monster(Type monster_type);
  Monster();

  static Monster GetRandomMonster();
  void EmptyMonster();
  bool IsEmpty();

  ~Monster();

 private:
  static const Creature& GetDefaultCreature(Type default_monster);
  bool empty;
};