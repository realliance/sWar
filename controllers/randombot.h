#pragma once
#include <card.h>
#include <playercontroller.h>

#include <string>
#include <vector>
namespace sWar {
struct Event;
}

using sWar::PlayerController, sWar::Event, sWar::Card;

class RandomBot : public PlayerController {
 public:
  auto ReceiveEvent(Event e) -> void;
  auto RetrieveCard() -> Card;
  auto Name() -> std::string { return "RandomBot"; }

 private:
  auto RandomCard() -> Card;
  std::vector<Card> hand;
};
