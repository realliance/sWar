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

auto sWar::Regroup(GameState& state) -> GameState& {
  for (const auto& victor : state.victors) {
    std::vector<Card> reinforcements;
    int availiableSoldiers = state.playerdecks.at(victor).size();
    int numSoldiers = availiableSoldiers > state.handsize ? state.handsize : state.playerdecks.at(victor).size();
    std::move(
      state.playerdecks.at(victor).begin(),
      state.playerdecks.at(victor).begin() + numSoldiers,
      reinforcements.begin());
    state.playerdecks.at(victor).erase(
      state.playerdecks.at(victor).begin(),
      state.playerdecks.at(victor).begin() + numSoldiers);

    state.hands.at(victor).insert(
      state.hands.at(victor).begin(),
      reinforcements.begin(), reinforcements.end());
    state.players.at(victor)->ReceiveEvent(Event{
      /*type: */ Event::Draw,
      /*playerCnt: */ 1,
      /*cardCnt: */ availiableSoldiers,
      /*players: */ {victor},
      /*cards: */ reinforcements,
      /*remainingCards: */ static_cast<int>(state.playerdecks.size())});
  }
  state.nextState = Duel;
  return state;
}
