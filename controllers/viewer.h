#pragma once

#include <playercontroller.h>

using sWar::PlayerController, sWar::Event, sWar::Card;

class Viewer : public PlayerController {
 public:
  Viewer(PlayerController* controller) : inst(controller) {}
  ~Viewer() { delete inst; }
  auto ReceiveEvent(Event e) -> void {
    std::cout << e << std::endl;
    inst->ReceiveEvent(e);
  }
  auto RetrieveCard() -> Card { return inst->RetrieveCard(); }
  auto Name() -> std::string { return inst->Name(); }

 private:
  PlayerController* inst;
};
