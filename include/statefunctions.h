#pragma once
#include "gamestate.h"
#include "settings.h"

namespace sWar {

auto StartGame(const GameSettings& settings, bool async) -> int;
auto ExitGame(int game) -> void;

auto StateController(const GameSettings& settings) -> void;

using StateFunction = auto (*)(GameState&) -> GameState&;

auto GameStart(GameState& state) -> GameState&;

auto Battle(GameState& state) -> GameState&;

auto Declaration(GameState& state) -> GameState&;

auto Regroup(GameState& state) -> GameState&;

auto Duel(GameState& state) -> GameState&;

auto Surrender(GameState& state) -> GameState&;

auto Collect(GameState& state) -> GameState&;

auto Draw(GameState& state) -> GameState&;

auto GameEnd(GameState& state) -> GameState&;

}  // namespace sWar
