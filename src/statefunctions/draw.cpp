#include <deque>
#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Draw(GameState& state) -> GameState& {
  for (const auto& deck : state.playerdecks) {
    if (deck.empty()) {
      state.nextState = GameEnd;
      return state;
    }
  }
  for (int i = 0; i < state.playerCnt; i++) {
    auto card = state.playerdecks.at(i).front();
    state.playerdecks.at(i).pop_front();

    state.hands.at(i).push_back(card);
    state.players.at(i)->ReceiveEvent(Event{
      /*type: */ Event::Draw,
      /*playerCnt: */ 1,
      /*cardCnt: */ 1,
      /*players: */ {i},
      /*cards: */ {card},
      /*remainingCards: */ static_cast<int>(state.playerdecks.size())});
  }
  state.nextState = Battle;
  return state;
}
