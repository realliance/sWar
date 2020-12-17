#pragma once
#include <string>
#include <vector>

namespace sWar {

struct GameSettings {
  std::vector<std::string> seatControllers{};
  uint64_t seed = 0;
  int deckCnt = 1;
  int handsize = 3;
  bool shuffleWinnings = true;
};

}  // namespace sWar
