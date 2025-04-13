#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Game.hpp"
#include "Monster.hpp"
#include "Player.hpp"

int main() {
  std::string playerName;
  std::cout << "Enter your Player name: ";
  std::cin >> playerName;

  Game g = Game(playerName);

  while (true) {
    bool res = g.PlayGame();

    if (!res) {
      break;
    }
  }

  std::cout << std::flush;
  std::cin.ignore();
  std::cin.get();

  return 0;
}