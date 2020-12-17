#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Draw(GameState& state) -> GameState& {
  for (int i = 0; i < state.playerCnt; i++) {
    if (state.decks.at(i).empty()) {
      continue;
    }
    auto card = state.decks.at(i).front();
    state.decks.at(i).pop_front();

    state.hands.at(i).push_back(card);
    state.players.at(i)->ReceiveEvent(Event{
      /*type: */ Event::Draw,
      /*playerCnt: */ 1,
      /*cardCnt: */ 1,
      /*players: */ {i},
      /*cards: */ {card},
      /*remainingCards: */ static_cast<int>(state.decks.at(i).size())});
  }
  state.nextState = Battle;
  return state;
}
