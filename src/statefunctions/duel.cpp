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

auto sWar::Duel(GameState& state) -> GameState& {
  Card highest(0);
  auto combatants = state.victors;
  state.victors.clear();
  for (const auto& combatant : combatants) {
    auto card = state.players.at(combatant)->RetrieveCard();

    bool found = false;
    for (const auto& soldier : state.hands.at(combatant)) {
      if (card == soldier) {
        found = true;
        break;
      }
    }

    if (!found) {
      card = state.hands.at(combatant).front();
    }

    state.hands.at(combatant).erase(
      std::find(state.hands.at(combatant).begin(), state.hands.at(combatant).end(), card));

    state.table.push_back(card);
    if (card.getCardNum() == highest.getCardNum()) {
      state.victors.push_back(combatant);
      continue;
    }

    if (card.getCardNum() > highest.getCardNum()) {
      highest = card;
      state.victors.clear();
      state.victors.push_back(combatant);
    }
  }
  state.nextState = state.victors.size() == 1 ? Collect : Declaration;
  return state;
}