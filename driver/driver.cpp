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
#include <duelist.h>
#include <highclass.h>

using sWar::StartGame, sWar::GameSettings, sWar::RegisterController;

auto main() -> int {
  RegisterController([](){
    return new RandomBot();
  }, "RandomBot");

  RegisterController([](){
    return new HighBot();
  }, "HighBot");

  RegisterController([](){
    return new ScoreRecorder(new DuelingBot());
  }, "DuelingBot");

  RegisterController([](){
    return new HighClassBot();
  }, "HighClassBot");

  RegisterController([](){
    return new LowBot();
  }, "LowBot");

  RegisterController([](){
    return new RandomBot();
  }, "RandomBot");

  std::vector<std::string> players = {"RandomBot", "HighBot", "LowBot", "RandomBot", "HighClassBot","DuelingBot"};

  const int iterations = 100000;

  for(int i = 0; i < iterations; i++){
    if(i % (iterations/100) == 0){
      std::cout << "\r" << i << "/" << iterations << std::flush;
    }
    sWar::StartGame(GameSettings{
      /* seatControllers: */ players,
      /* seed: */ 0,
      /* decks: */ 2,
      /* handsize: */ 3,
      /* shuffleWinnings: */ true
    }, /* async: */ false);
  }

  std::cout << "\rIterations: " << iterations << std::endl;
  std::cout << std::endl;

  std::vector<std::pair<int,int>> wins(ScoreRecorder::Wins.begin(), ScoreRecorder::Wins.end());
  std::sort(wins.begin(), wins.end(), [](std::pair<int,int> a, std::pair<int,int> b) {
    return a.second > b.second;
  });
  for(const auto & [playerID,wins] : wins){
    std::cout << players.at(playerID) << "(" << playerID << "): " << wins << std::endl;
  }

  return 0;
}
