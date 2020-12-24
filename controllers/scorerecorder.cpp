#include "scorerecorder.h"

#include <vector>

#include "event.h"
#include "playercontroller.h"

std::map<std::string, int> ScoreRecorder::Wins;

auto ScoreRecorder::ReceiveEvent(Event e) -> void {
  if (e.type == Event::GameStart) {
    playerID = e.players.front();
  }
  if (e.type == Event::GameEnd) {
    for (const auto& player : e.players) {
      if (player != playerID) {
        continue;
      }
      if (Wins.contains(inst->Name())) {
        Wins.at(inst->Name())++;
      } else {
        Wins[inst->Name()] = 1;
      }
    }
  }
  inst->ReceiveEvent(e);
}
