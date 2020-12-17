#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "card.h"

namespace sWar {

struct Event {
  enum Type {
    Draw,
    PlayCard,
    DeclarationOfWar,
    War,
    Victory,
    GameStart,
    GameEnd
  };
  Type type = {};
  int playerCnt = {};
  int cardCnt = {};
  std::vector<int> players = {};
  std::vector<Card> cards = {};
  int remainingCards = {};
};

inline auto EventTypeToStr(Event::Type s) -> std::string {
  switch (s) {
    case Event::Draw:
      return "Draw";
    case Event::PlayCard:
      return "PlayCard";
    case Event::DeclarationOfWar:
      return "DeclarationOfWar";
    case Event::War:
      return "War";
    case Event::Victory:
      return "Victory";
    case Event::GameStart:
      return "GameStart";
    case Event::GameEnd:
      return "GameEnd";
    default:
      return "InvalidState";
  }
}

}  // namespace sWar

auto operator<<(std::ostream& os, const sWar::Event& e) -> std::ostream&;
