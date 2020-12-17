#include <stddef.h>

#include <algorithm>
#include <deque>
#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Surrender(GameState& state) -> GameState& {
  int winnings = state.table.size() / (state.victors.size() - state.casualties.size());
  for (const auto& victor : state.victors) {
    std::move(
      state.table.begin(),
      state.table.begin() + winnings,
      std::back_inserter(state.playerdecks.at(victor)));
    state.table.erase(
      state.table.begin(),
      state.table.begin() + winnings);
  }
  state.nextState = GameEnd;
  return state;
}
