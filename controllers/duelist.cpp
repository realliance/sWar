#include "duelist.h"

#include <card.h>
#include <event.h>

#include <algorithm>

auto DuelingBot::ReceiveEvent(Event e) -> void {
  switch (e.type) {
    case Event::GameStart:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::Draw:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::DeclarationOfWar:
      dueling = true;
      return;
    case Event::Victory:
      return;
    case Event::GameEnd:
      return;
    default:
      return;
  }
}

auto DuelingBot::RetrieveCard() -> Card {
  auto card = PickCard();
  dueling = false;
  return card;
}

auto DuelingBot::PickCard() -> Card {
  if (hand.empty()) {
    // We can try lmao
    return Card(Card::ACE_OF_SPADES);
  }
  if (hand.size() == 1) {
    auto card = hand.back();
    hand.pop_back();
    return card;
  }
  std::sort(hand.begin(), hand.end(), [](Card a, Card b) {
    return a.getCardNum() > b.getCardNum();
  });

  Card c;
  if (dueling) {
    c = hand.at(0);
  } else {
    c = hand.at(1);
  }

  hand.erase(
    std::find(hand.begin(), hand.end(), c));
  return c;
}
