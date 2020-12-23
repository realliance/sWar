#include <algorithm>
#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Declaration(GameState& state) -> GameState& {
  for (const auto& victor : state.victors) {
    if (state.hands.at(victor).empty()) {
      state.casualties.push_back(victor);
      continue;
    }

    if (state.decks.at(victor).size() <= 3) {
      state.table.insert(
        state.table.begin(),
        state.decks.at(victor).begin(),
        state.decks.at(victor).end());
      state.decks.at(victor).clear();
      continue;
    }

    state.table.insert(
      state.table.begin(),
      state.decks.at(victor).begin(),
      state.decks.at(victor).begin() + 3);
    state.decks.at(victor).erase(
      state.decks.at(victor).begin(),
      state.decks.at(victor).begin() + 3);
  }
  for (const auto& casuality : state.casualties) {
    state.victors.erase(
      std::find(state.victors.begin(), state.victors.end(), casuality));
  }

  for (int i = 0; i < state.playerCnt; i++) {
    state.players.at(i)->ReceiveEvent(
      Event{
        /*type: */ Event::DeclarationOfWar,
        /*playerCnt: */ static_cast<int>(state.victors.size()),
        /*cardCnt: */ 0,
        /*players: */ state.victors,
        /*cards: */ {},
        /*remainingCards: */ static_cast<int>(state.decks.at(i).size())});
  }

  if (!state.casualties.empty()) {
    state.nextState = Surrender;
    return state;
  }

  state.nextState = Regroup;
  return state;
}
