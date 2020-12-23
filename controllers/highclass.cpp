#include "highclass.h"

#include <card.h>
#include <event.h>

#include <algorithm>

auto HighClassBot::ReceiveEvent(Event e) -> void {
  switch (e.type) {
    case Event::GameStart:
      hand.insert(hand.begin(), e.cards.begin(), e.cards.end());
      return;
    case Event::Draw:
      TakeCards(e.cards);
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

auto HighClassBot::TakeCards(std::vector<Card> cards) -> void {
  //lowest to highest (high ace)
  std::sort(cards.begin(), cards.end(), [](Card a, Card b) {
    return a.getCardNum() < b.getCardNum();
  });
  if (cards.back().getCardNum() >= Card::JACK) {
    if (reserve == Card(Card::ERROR)) {
      reserve = cards.back();
      cards.pop_back();
    } else if (cards.back().getCardNum() > reserve.getCardNum()) {
      hand.push_back(reserve);
      reserve = cards.back();
      cards.pop_back();
    }
  }
  if (cards.empty()) {
    return;
  }
  hand.insert(hand.begin(), cards.begin(), cards.end());
}

auto HighClassBot::RetrieveCard() -> Card {
  Card card;
  if (!dueling || reserve == Card(Card::ERROR)) {
    card = PickCard();
  } else {
    card = reserve;
    reserve = Card(Card::ERROR);
  }
  dueling = false;
  return card;
}

auto HighClassBot::PickCard() -> Card {
  if (hand.empty()) {
    auto card = reserve;
    reserve = Card(Card::ERROR);
    return card;
  }
  if (hand.size() == 1) {
    auto card = hand.back();
    hand.pop_back();
    return card;
  }
  //highest to lowest (high ace)
  std::sort(hand.begin(), hand.end(), [](Card a, Card b) {
    return a.getCardNum() > b.getCardNum();
  });

  Card c = hand.at(0);

  hand.erase(
    std::find(hand.begin(), hand.end(), c));
  return c;
}
