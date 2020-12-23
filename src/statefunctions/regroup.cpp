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

auto sWar::Regroup(GameState& state) -> GameState& {
  for (const auto& victor : state.victors) {
    if (state.decks.at(victor).empty()) {
      continue;
    }
    state.hands.at(victor).push_back(state.decks.at(victor).front());
    state.players.at(victor)->ReceiveEvent(Event{
      /*type: */ Event::Draw,
      /*playerCnt: */ 1,
      /*cardCnt: */ 1,
      /*players: */ {victor},
      /*cards: */ {state.decks.at(victor).front()},
      /*remainingCards: */ static_cast<int>(state.decks.size())});
    state.decks.at(victor).pop_front();
  }
  state.nextState = Duel;
  return state;
}
