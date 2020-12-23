#include "highbot.h"

#include <card.h>
#include <event.h>

#include <algorithm>

auto HighBot::ReceiveEvent(Event e) -> void {
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

auto HighBot::RetrieveCard() -> Card {
  return TopCard();
}

auto HighBot::TopCard() -> Card {
  if (hand.empty()) {
    return Card(Card::ERROR);
  }
  Card highest = hand.front();
  for (const auto& card : hand) {
    if (card.getCardNum() > highest.getCardNum()) {
      highest = card;
    }
  }
  hand.erase(
    std::find(hand.begin(), hand.end(), highest));
  return highest;
}
