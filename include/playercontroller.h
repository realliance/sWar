#pragma once
#include <array>
#include <string>
#include <vector>

#include "event.h"
namespace sWar {

//NOLINTNEXTLINE(cppcoreguidelines-special-member-functions,hicpp-special-member-functions)
class PlayerController {
 public:
  virtual ~PlayerController() = default;
  virtual auto ReceiveEvent(Event e) -> void = 0;
  virtual auto RetrieveCard() -> Card = 0;
  virtual auto Name() -> std::string = 0;
};

}  // namespace sWar
