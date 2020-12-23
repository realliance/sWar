#pragma once
#include <card.h>
#include <playercontroller.h>

#include <string>
#include <vector>
namespace sWar {
struct Event;
}

using sWar::PlayerController, sWar::Event, sWar::Card;

class HighClassBot : public PlayerController {
 public:
  auto ReceiveEvent(Event e) -> void;
  auto RetrieveCard() -> Card;
  auto Name() -> std::string { return "HighClassBot"; }

 private:
  auto PickCard() -> Card;
  auto TakeCards(std::vector<Card> cards) -> void;
  bool dueling = false;
  std::vector<Card> hand;
  Card reserve = Card(Card::ERROR);
};
