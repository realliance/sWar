#include <atomic>
#include <fstream>
#include <iomanip>
#include <set>
#include <thread>

#include <controllermanager.h>
#include <gamestate.h>
#include <playercontroller.h>
#include <statefunctions.h>

#include <scorerecorder.h>
#include <highbot.h>
#include <lowbot.h>
#include <randombot.h>

using sWar::StartGame, sWar::GameSettings, sWar::RegisterController;

auto main() -> int {
  RegisterController([](){
    return new ScoreRecorder(new RandomBot());
  }, "RandomBot");

  RegisterController([](){
    return new HighBot();
  }, "HighBot");

  RegisterController([](){
    return new LowBot();
  }, "LowBot");

  RegisterController([](){
    return new RandomBot();
  }, "RandomBot");

  std::vector<std::string> players = {"RandomBot","HighBot","LowBot"};

  const int iterations = 100000;

  for(int i = 0; i < iterations; i++){
    if(i % (iterations/100) == 0){
      std::cout << i << std::endl;
    }
    sWar::StartGame(GameSettings{
      /* seatControllers: */ players,
      /* seed: */ 0,
      /* decks: */ 1,
      /* handsize: */ 3,
      /* shuffleWinnings: */ true
    }, /* async: */ false);
  }

  for(const auto & [playerID,wins] : ScoreRecorder::Wins){
    std::cout << players.at(playerID) << "(" << playerID << "): " << wins << std::endl;
  }

  return 0;
}
