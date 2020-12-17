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
    std::vector<Card> reinforcements;
    int availiableSoldiers = state.decks.at(victor).size();
    int numSoldiers = availiableSoldiers > state.handsize ? state.handsize : state.decks.at(victor).size();
    std::move(
      state.decks.at(victor).begin(),
      state.decks.at(victor).begin() + numSoldiers,
      std::back_inserter(reinforcements));
    state.decks.at(victor).erase(
      state.decks.at(victor).begin(),
      state.decks.at(victor).begin() + numSoldiers);

    state.hands.at(victor).insert(
      state.hands.at(victor).begin(),
      reinforcements.begin(), reinforcements.end());
    state.players.at(victor)->ReceiveEvent(Event{
      /*type: */ Event::Draw,
      /*playerCnt: */ 1,
      /*cardCnt: */ availiableSoldiers,
      /*players: */ {victor},
      /*cards: */ reinforcements,
      /*remainingCards: */ static_cast<int>(state.decks.size())});
  }
  state.nextState = Duel;
  return state;
}
