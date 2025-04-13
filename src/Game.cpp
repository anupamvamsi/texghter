#include "Game.hpp"

#include <iostream>

#include "Monster.hpp"
#include "Player.hpp"
#include "Random.hpp"

Game::Game(const std::string& playerName) 
    : m{Monster::GetRandomMonster()}, p{new Player(playerName)} {}

bool Game::PlayGame() {
  if (!this->FightMonster()) {
    return this->PlayAgain();
  }
  return true;
}

char Game::MakeChoice() {
  char choice;
  std::cout << "[R]un to live and fight another day, or [F]ight standing your "
               "ground? ";
  std::cin >> choice;
  choice = tolower(choice, std::locale());

  return choice;
}

bool Game::TryRun() {
  bool run = static_cast<bool>(GenerateRandomNum(0, 1));

  if (run) {  // run success
    std::cout << "You managed to escape!\n\n";
    return true;
  }

  // run fail
  std::cout << "You failed to run... Look out, an attack!\n";
  return false;
}

bool Game::FightMonster() {
  char choice = Game::MakeChoice();

  if (choice == 'r') {     // Choice Run
    if (Game::TryRun()) {  // Run success
      this->m = Monster::GetRandomMonster();
      return true;
    }

    // Run failed
    this->AttackPlayer();

    if (this->p->IsDead()) {  // Player Dead
      this->HasLost();
      return false;
    }

    return true;
  }

  else if (choice == 'f') {  // Choice Fight
    this->AttackMonster();

    if (this->m.IsDead()) {  // Monster Dead
      this->MonsterDead();

      if (this->p->HasWon()) {  // Level is now 20
        std::cout << "You win! You have ⛁ " << this->p->GetGold() << " gold!\n";
        return false;
      }

      // Level not yet 20
      return true;
    }

    // Monster Alive
    this->AttackPlayer();

    if (this->p->IsDead()) {  // Player Dead
      this->HasLost();
      return false;
    }

    return true;
  }
  return true;
}

void Game::AttackMonster() {
  this->m.ReduceHealth(this->p->GetDamage());

  std::cout << "You hit the " << this->m.GetName() << " for "
            << this->p->GetDamage() << " damage.\n";
}

void Game::AttackPlayer() {
  this->p->ReduceHealth(this->m.GetDamage());

  std::cout << "The " << this->m.GetName() << " attacked you for "
            << this->m.GetDamage() << " damage.\n";
}

void Game::HasLost() {
  std::cout << "\nYou lost at Level " << this->p->GetLevel() << " and with "
            << this->p->GetGold() << " gold. Too bad, try again, maybe!\n";
}

void Game::MonsterDead() {
  this->p->AddGold(this->m.GetGold());
  this->p->LevelUp();

  std::cout << "You killed the " << this->m.GetName() << ".\n";
  std::cout << "You are now Level " << this->p->GetLevel() << ".\n";
  std::cout << "You found " << this->m.GetGold() << " gold.\n";

  this->p->PrintStats();
  this->m = Monster::GetRandomMonster();
}

bool Game::PlayAgain() {
  std::cout << "[R]estart game or [E]xit? ";
  char choice;
  std::cin >> choice;
  choice = std::tolower(choice, std::locale());

  if (choice == 'r') {
    this->p->ResetStats();
    this->p->PrintStats();
    this->m = Monster::GetRandomMonster();
    return true;
  }

  this->p->~Player();
  return false;
}