#include <algorithm>
#include <deque>
#include <memory>
#include <vector>

#include "card.h"
#include "deck.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::GameStart(GameState& state) -> GameState& {
  for (int i = 0; i < state.decks; i++) {
    std::copy(
      DECK.begin(),
      DECK.end(),
      state.table.begin());
  }
  std::shuffle(state.table.begin(), state.table.end(), state.g);

  state.playerdecks.resize(state.players.size());
  int i = 0;
  for (auto& playerdeck : state.playerdecks) {
    std::move(
      state.table.begin(),
      state.table.begin() + ((52 * state.decks) / state.playerCnt),
      playerdeck.begin());
    state.table.erase(
      state.table.begin(),
      state.table.begin() + ((52 * state.decks) / state.playerCnt));
    std::move(
      playerdeck.begin(),
      playerdeck.begin() + state.handsize,
      state.hands.at(i).begin());
    playerdeck.erase(
      playerdeck.begin(),
      playerdeck.begin() + state.handsize);
    i++;
  }
  for (int i = 0; i < state.playerCnt; i++) {
    state.players.at(i)->ReceiveEvent(
      Event{
        /*type: */ Event::GameStart,
        /*playerCnt: */ 1,
        /*cardCnt: */ state.handsize,
        /*players: */ {i},
        /*cards: */ state.hands.at(i),
        /*remainingCards: */ static_cast<int>(state.playerdecks.at(i).size())});
  }

  state.nextState = Battle;
  return state;
}
