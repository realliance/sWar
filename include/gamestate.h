#pragma once
#include <cstdint>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

#include "card.h"

namespace sWar {
class PlayerController;

struct GameState {
  int deckCnt = 1;
  int handsize = 3;
  int playerCnt = 2;
  bool shuffleWinnings = true;
  uint64_t seed = 0;
  std::mt19937 g;
  auto (*prevState)(struct GameState&) -> struct GameState&;
  auto (*currState)(struct GameState&) -> struct GameState&;
  auto (*nextState)(struct GameState&) -> struct GameState&;
  std::vector<int> victors;
  std::vector<int> casualties;
  std::vector<std::vector<Card>> hands;
  std::vector<std::deque<Card>> decks;
  std::vector<PlayerController*> players;
  std::vector<Card> table;
};

}  // namespace sWar

auto operator<<(std::ostream& os, const sWar::GameState& state) -> std::ostream&;
