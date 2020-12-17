#include <atomic>
#include <fstream>
#include <iomanip>
#include <set>
#include <thread>

#include <controllermanager.h>
#include <gamestate.h>
#include <playercontroller.h>
#include <statefunctions.h>

#include <viewer.h>
#include <highbot.h>
#include <lowbot.h>

using sWar::StartGame, sWar::GameSettings, sWar::RegisterController;

auto main() -> int {
  RegisterController([](){
    return new Viewer(new HighBot());
  }, "ViewerHighBot");

  RegisterController([](){
    return new LowBot();
  }, "LowBot");

  sWar::StartGame(GameSettings{
    /* seatControllers: */ {"ViewerHighBot","LowBot"},
    /* seed: */ 0,
    /* decks: */ 1,
    /* handsize: */ 3,
    /* shuffleWinnings: */ true
  }, /* async: */ false);

  return 0;
}
