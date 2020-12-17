#include "scorerecorder.h"

#include <vector>

#include "event.h"
#include "playercontroller.h"

std::map<int, int> ScoreRecorder::Wins;

auto ScoreRecorder::ReceiveEvent(Event e) -> void {
  if (e.type == Event::GameEnd) {
    for (const auto& player : e.players) {
      if (Wins.contains(player)) {
        Wins.at(player)++;
      } else {
        Wins[player] = 1;
      }
    }
  }
  inst->ReceiveEvent(e);
}
