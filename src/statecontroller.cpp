#include <cstddef>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <thread>
#include <vector>

#include "controllermanager.h"
#include "gamestate.h"
#include "settings.h"
#include "statefunctions.h"

namespace sWar {
class PlayerController;
}  // namespace sWar

static int threadIndex = 1;
static std::map<int, bool> shouldHalt;

auto sWar::StartGame(const GameSettings& settings, bool async) -> int {
  if (async) {
    std::thread gameloop(&sWar::StateController, settings);
    gameloop.detach();
    return threadIndex;
  }
  StateController(settings);
  return 0;
}

auto sWar::ExitGame(int game) -> void {
  if (shouldHalt.contains(game)) {
    std::cerr << "Halting Game..." << std::endl;
    shouldHalt[game] = true;
  }
}

auto sWar::StateController(const GameSettings& settings) -> void {
  GameState state;
  int id = threadIndex++;
  shouldHalt[id] = false;

  state.handsize = settings.handsize;
  state.deckCnt = settings.deckCnt;
  state.playerCnt = static_cast<size_t>(settings.seatControllers.size());
  state.shuffleWinnings = settings.shuffleWinnings;

  if (settings.seatControllers.size() < 2) {
    std::cerr << "Not Enough Players: " << settings.seatControllers.size() << std::endl;
    return;
  }

  for (const auto& controllerName : settings.seatControllers) {
    auto* controller = GetController(controllerName);
    state.players.push_back(controller);
    if (controller == nullptr) {
      std::cerr << "No such Controller: " << controllerName << std::endl;
      return;
    }
  }

  if (settings.seed != 0u) {
    state.seed = settings.seed;
  } else {
    std::random_device rd;
    state.seed = rd();
  }
  state.g.seed(state.seed);
  state.prevState = nullptr;
  state.currState = GameStart;
  state.nextState = GameStart;

  while (state.nextState != GameEnd && !shouldHalt[id]) {
    // std::cout << state << std::endl;
    state.prevState = state.currState;
    state.currState = state.nextState;
    state = state.nextState(state);
  }

  if (state.nextState == GameEnd) {
    state.nextState(state);
  }
}
