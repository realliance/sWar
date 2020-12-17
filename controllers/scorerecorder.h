#pragma once
#include <playercontroller.h>

#include <map>
#include <string>

#include "card.h"
namespace sWar {
struct Event;
}

using sWar::PlayerController, sWar::Event, sWar::Card;

class ScoreRecorder : public PlayerController {
 public:
  ScoreRecorder(PlayerController* controller) : inst(controller) {}
  ~ScoreRecorder() { delete inst; }
  auto ReceiveEvent(Event e) -> void;
  auto RetrieveCard() -> Card { return inst->RetrieveCard(); }
  auto Name() -> std::string { return inst->Name(); }
  static std::map<int, int> Wins;

 private:
  PlayerController* inst;
};
