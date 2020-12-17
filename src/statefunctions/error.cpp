#include <iostream>
#include <stdexcept>

#include "gamestate.h"
#include "statefunctions.h"

auto sWar::Error(GameState& state) -> GameState& {
  std::cerr << "ERROR STATE REACHED" << std::endl;
  std::cerr << "GameState: " << std::endl;
  std::cerr << state;
  throw std::runtime_error("ERROR STATE REACHED");
}
