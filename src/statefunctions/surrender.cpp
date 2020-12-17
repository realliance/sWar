#include <algorithm>
#include <deque>
#include <iterator>
#include <vector>

#include "card.h"
#include "gamestate.h"
#include "statefunctions.h"

auto sWar::Surrender(GameState& state) -> GameState& {
  int winnings = state.table.size() / (state.victors.size());
  for (const auto& victor : state.victors) {
    std::move(
      state.table.begin(),
      state.table.begin() + winnings,
      std::back_inserter(state.decks.at(victor)));
    state.table.erase(
      state.table.begin(),
      state.table.begin() + winnings);
  }
  state.nextState = GameEnd;
  return state;
}
