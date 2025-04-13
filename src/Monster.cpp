#include "Monster.hpp"

#include <array>
#include <iostream>
#include <random>

#include "Player.hpp"
#include "Random.hpp"

Monster::Monster(Type monster_type)
    : Creature(GetDefaultCreature(monster_type)), empty{false} {
  std::cout << "A " << this->GetName() << " (" << this->GetSymbol()
            << ") has appeared.\n";
}

Monster::Monster() : empty{true} {}

void Monster::EmptyMonster() { this->empty = true; }

Monster Monster::GetRandomMonster() {
  int rand_num =
      GenerateRandomNum(0, static_cast<int>(Monster::Type::max_types) - 1);
  return Monster{static_cast<Monster::Type>(rand_num)};
}

bool Monster::IsEmpty() { return this->empty; }

const Creature& Monster::GetDefaultCreature(Type monster_type) {
  static std::array<Creature, static_cast<std::size_t>(Type::max_types)>
      MonsterData{
          //
          {{"Dragon", 'D', 20, 9, 100},
           {"Orc", 'O', 4, 2, 25},
           {"Slime", 'S', 1, 1, 10},
           {"Leprechaun", 'L', 7, 4, 1000},
           {"Snagli", 'I', 9, 2, 50},
           {"Cockroach", 'C', 15, 0, 0},
           {"Pigeon", 'P', 2, 1, 500}}
          /**/
      };

  std::size_t index = static_cast<std::size_t>(monster_type);
  return MonsterData.at(index);
}

Monster::~Monster() {}