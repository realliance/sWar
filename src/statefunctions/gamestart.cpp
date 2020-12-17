#include <algorithm>
#include <deque>
#include <iterator>
#include <memory>
#include <vector>

#include "card.h"
#include "deck.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::GameStart(GameState& state) -> GameState& {
  for (int i = 0; i < state.deckCnt; i++) {
    std::copy(
      DECK.begin(),
      DECK.end(),
      std::back_inserter(state.table));
  }
  std::shuffle(state.table.begin(), state.table.end(), state.g);

  for (int i = 0; i < state.playerCnt; i++) {
    state.decks.push_back({});
    state.hands.push_back({});
    std::move(
      state.table.begin(),
      state.table.begin() + ((52 * state.deckCnt) / state.playerCnt),
      std::back_inserter(state.decks.at(i)));
    state.table.erase(
      state.table.begin(),
      state.table.begin() + ((52 * state.deckCnt) / state.playerCnt));
    std::move(
      state.decks.at(i).begin(),
      state.decks.at(i).begin() + state.handsize,
      std::back_inserter(state.hands.at(i)));
    state.decks.at(i).erase(
      state.decks.at(i).begin(),
      state.decks.at(i).begin() + state.handsize);
  }
  for (int i = 0; i < state.playerCnt; i++) {
    state.players.at(i)->ReceiveEvent(
      Event{
        /*type: */ Event::GameStart,
        /*playerCnt: */ 1,
        /*cardCnt: */ state.handsize,
        /*players: */ {i},
        /*cards: */ state.hands.at(i),
        /*remainingCards: */ static_cast<int>(state.decks.at(i).size())});
  }

  state.nextState = Battle;
  return state;
}
