#include "lowbot.h"

#include <card.h>
#include <event.h>

#include <algorithm>

auto LowBot::ReceiveEvent(Event e) -> void {
  switch (e.type) {
    case Event::GameStart:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::Draw:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::DeclarationOfWar:
      hand.clear();
      return;
    case Event::Victory:
      return;
    case Event::GameEnd:
      return;
    default:
      return;
  }
}

auto LowBot::RetrieveCard() -> Card {
  return BottomCard();
}

auto LowBot::BottomCard() -> Card {
  if (hand.empty()) {
    // We can try lmao
    return Card(Card::ACE_OF_SPADES);
  }
  Card highest = hand.front();
  for (const auto& card : hand) {
    if (card.getCardNum() < highest.getCardNum()) {
      highest = card;
    }
  }
  hand.erase(
    std::find(hand.begin(), hand.end(), highest));
  return highest;
}