#include "controllermanager.h"

#include <map>
#include <string>
#include <utility>
#include <vector>

using sWar::newControllerInst;

static std::map<std::string, newControllerInst> availableControllers = {};

auto sWar::GetAvailableControllers() -> std::vector<std::string> {
  std::vector<std::string> names;
  names.reserve(availableControllers.size());
  for (const auto& [name, _] : availableControllers) {
    names.push_back(name);
  }
  return names;
}

auto sWar::GetController(const std::string& controller) -> PlayerController* {
  if (availableControllers.contains(controller)) {
    return availableControllers[controller]();
  }
  return nullptr;
}

auto sWar::RegisterController(newControllerInst newFunc, const std::string& name) -> bool {
  if (availableControllers.contains(name)) {
    return false;
  }
  availableControllers[name] = std::move(newFunc);
  return true;
}
