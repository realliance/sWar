#include "randombot.h"

#include <card.h>
#include <event.h>

#include <algorithm>

auto RandomBot::ReceiveEvent(Event e) -> void {
  switch (e.type) {
    case Event::GameStart:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::Draw:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::DeclarationOfWar:
      return;
    case Event::Victory:
      return;
    case Event::GameEnd:
      return;
    default:
      return;
  }
}

auto RandomBot::RetrieveCard() -> Card {
  return RandomCard();
}

auto RandomBot::RandomCard() -> Card {
  if (hand.empty()) {
    return Card(Card::ERROR);
  }
  Card random = hand.front();
  hand.erase(
    std::find(hand.begin(), hand.end(), random));
  return random;
}
