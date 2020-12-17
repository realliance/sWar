#include "event.h"

#include <iostream>

#include "card.h"

using sWar::Event, sWar::EventTypeToStr;

auto operator<<(std::ostream& os, const Event& e) -> std::ostream& {
  os << "{type: " << EventTypeToStr(e.type);
  os << ", playerCnt: " << e.playerCnt;
  os << ", cardCnt: " << e.cardCnt;
  os << ", players: [";
  for (const auto& player : e.players) {
    os << player;
  }
  os << "], cards: [";
  for (const auto card : e.cards) {
    os << card.toStr() << ", ";
  }
  os << "], remainingCards: " << static_cast<int>(e.remainingCards) << "}";
  return os;
}
