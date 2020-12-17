#include "gamestate.h"

#include <map>
#include <string>

#include "playercontroller.h"
#include "statefunctions.h"

using sWar::GameState, sWar::StateFunction;

const std::map<StateFunction, std::string> FUNCMAP = {
  {sWar::GameStart, "GameStart"},
  {sWar::Battle, "Battle"},
  {sWar::Declaration, "Declaration"},
  {sWar::Regroup, "Regroup"},
  {sWar::Duel, "Duel"},
  {sWar::Surrender, "Surrender"},
  {sWar::Collect, "Collect"},
  {sWar::Draw, "Draw"},
  {sWar::GameEnd, "GameEnd"}};

auto stateFunctionToStr(StateFunction func) -> std::string {
  if (FUNCMAP.contains(func)) {
    return FUNCMAP.at(func);
  }
  return "UNKNOWN STATE";
}

auto operator<<(std::ostream& os, const GameState& state) -> std::ostream& {
  os << "decks: " << state.deckCnt << std::endl;
  os << "handsize: " << state.handsize << std::endl;
  os << "shuffleWinnings: " << (state.shuffleWinnings ? "true" : "false") << std::endl;
  os << "seed: " << state.seed << std::endl;
  os << "prevState: " << stateFunctionToStr(state.prevState) << std::endl;
  os << "currState: " << stateFunctionToStr(state.currState) << std::endl;
  os << "nextState: " << stateFunctionToStr(state.nextState) << std::endl;
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
  for (const auto& hand : state.decks) {
    os << "deck[" << i << "]: {";
    for (const auto card : hand) {
      os << card.toStr() << ", ";
    }
    os << "}" << std::endl;
    i++;
  }
  i = 0;
  for (const auto& player : state.players) {
    os << "player[" << i << "]: "
       << "{ controller: ";
    os << ((player != nullptr) ? player->Name() : "NULLPTR");
    os << "}" << std::endl;
    i++;
  }
  os << "table: {";
  for (const auto card : state.table) {
    os << card.toStr() << ", ";
  }
  os << "}" << std::endl;
  return os;
}
