#include <cstddef>
#include <memory>
#include <vector>

#include "card.h"
#include "event.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::GameEnd(GameState& state) -> GameState& {
  std::vector<int> winners;
  size_t winnings = 0;
  for (int i = 0; i < state.playerCnt; i++) {
    if ((state.hands.at(i).size() + state.decks.at(i).size()) == winnings) {
      winners.push_back(i);
      continue;
    }
    if ((state.hands.at(i).size() + state.decks.at(i).size()) > winnings) {
      winners.clear();
      winnings = (state.hands.at(i).size() + state.decks.at(i).size());
      winners.push_back(i);
    }
  }
  for (auto& player : state.players) {
    player->ReceiveEvent(
      Event{
        /*type: */ Event::GameEnd,
        /*playerCnt: */ static_cast<int>(winners.size()),
        /*cardCnt: */ 0,
        /*players: */ winners,
        /*cards: */ {},
        /*remainingCards: */ static_cast<int>(winnings)});
    delete player;
    player = nullptr;
  }
  state.players.clear();
  return state;
}
