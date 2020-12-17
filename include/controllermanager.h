#pragma once
#include <functional>
#include <string>
#include <vector>

namespace sWar {
class PlayerController;
}  // namespace sWar

namespace sWar {
using newControllerInst = std::function<PlayerController*()>;

auto GetAvailableControllers() -> std::vector<std::string>;
auto GetController(const std::string& controller) -> PlayerController*;
auto RegisterController(newControllerInst newFunc, const std::string& Name) -> bool;
}  // namespace sWar
