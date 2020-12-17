#include <algorithm>
#include <deque>
#include <iterator>
#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Collect(GameState& state) -> GameState& {
  for (int i = 0; i < state.playerCnt; i++) {
    state.players.at(i)->ReceiveEvent(
      Event{
        /*type: */ Event::Victory,
        /*playerCnt: */ 1,
        /*cardCnt: */ static_cast<int>(state.table.size()),
        /*players: */ {state.victors.front()},
        /*cards: */ state.table,
        /*remainingCards: */ static_cast<int>(state.decks.at(i).size())});
  }
  if (state.shuffleWinnings) {
    std::shuffle(state.table.begin(), state.table.end(), state.g);
  }
  std::move(
    state.table.begin(),
    state.table.end(),
    std::back_inserter(state.decks.at(state.victors.front())));
  state.victors.clear();
  state.table.clear();
  state.nextState = Draw;
  return state;
}
