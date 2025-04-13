#include "Monster.hpp"
#include "Player.hpp"

class Game {
 public:
  Game(const std::string& playerName);
  Game(const Game&) = delete;  // Delete copy constructor
  Game& operator=(const Game&) = delete;  // Delete assignment operator
  static char MakeChoice();
  static bool TryRun();
  bool FightMonster();
  void AttackMonster();
  void AttackPlayer();
  void HasLost();
  void MonsterDead();
  bool PlayAgain();
  bool PlayGame();

 private:
  Monster m;
  Player* p;
};