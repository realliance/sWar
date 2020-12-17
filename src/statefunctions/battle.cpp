#include <algorithm>
#include <ext/alloc_traits.h>
#include <memory>
#include <vector>

#include "card.h"
#include "gamestate.h"
#include "playercontroller.h"
#include "statefunctions.h"

auto sWar::Battle(GameState& state) -> GameState& {
  for (const auto& hand : state.hands) {
    if (hand.empty()) {
      state.nextState = GameEnd;
      return state;
    }
  }

  Card highest(0);
  for (int i = 0; i < state.playerCnt; i++) {
    auto card = state.players.at(i)->RetrieveCard();

    bool found = false;
    for (const auto& soldier : state.hands.at(i)) {
      if (card == soldier) {
        found = true;
        break;
      }
    }

    if (!found) {
      card = state.hands.at(i).front();
    }

    state.hands.at(i).erase(
      std::find(state.hands.at(i).begin(), state.hands.at(i).end(), card));

    state.table.push_back(card);
    if (card.getCardNum() == highest.getCardNum()) {
      state.victors.push_back(i);
      continue;
    }

    if (card.getCardNum() > highest.getCardNum()) {
      highest = card;
      state.victors.clear();
      state.victors.push_back(i);
    }
  }
  state.nextState = state.victors.size() == 1 ? Collect : Declaration;
  return state;
}
