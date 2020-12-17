#include "gamestate.h"

#include <string>

#include "playercontroller.h"

using sWar::GameState;

auto operator<<(std::ostream& os, const GameState& state) -> std::ostream& {
  os << "decks: " << state.decks << std::endl;
  os << "handsize: " << state.handsize << std::endl;
  os << "shuffleWinnings: " << (state.shuffleWinnings ? "true" : "false") << std::endl;
  os << "seed: " << state.seed << std::endl;
  os << "victors: [" << std::endl;
  for (const auto& victor : state.victors) {
    os << victor << ", ";
  }
  os << "] " << std::endl;
  os << "hands: " << std::endl;
  int i = 0;
  for (const auto& hand : state.hands) {
    os << "hand[" << i << "]: {";
    for (const auto card : hand) {
      os << card.toStr() << ", ";
    }
    os << "}" << std::endl;
    i++;
  }
  os << "player decks: " << std::endl;
  i = 0;
  for (const auto& hand : state.playerdecks) {
    os << "deck[" << i << "]: {";
    for (const auto card : hand) {
      os << card.toStr() << ", ";
    }
    os << "}" << std::endl;
    i++;
  }
  os << "players: " << std::endl;
  i = 0;
  for (const auto& player : state.players) {
    os << "player[" << i << "]: "
       << "{ controller: ";
    os << ((player != nullptr) ? player->Name() : "NULLPTR");
    os << std::endl;
    i++;
  }
  os << "table: {";
  for (const auto card : state.table) {
    os << card.toStr() << ", ";
  }
  os << "}" << std::endl;
  return os;
}
