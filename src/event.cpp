#include "event.h"

#include <iostream>

#include "card.h"

using sWar::Event, sWar::EventTypeToStr;

auto operator<<(std::ostream& os, const Event& e) -> std::ostream& {
  os << "{type: " << EventTypeToStr(e.type);
  os << ", playerCnt: " << e.playerCnt;
  os << ", cardCnt: " << e.cardCnt;
  os << "players: " << std::endl;
  for (const auto& player : e.players) {
    os << "player[" << player << "], ";
  }
  os << std::endl;
  os << ", cards: [";
  for (const auto card : e.cards) {
    os << card.toStr() << ", ";
  }
  os << "remainingCards: " << e.remainingCards << "}";
  return os;
}
