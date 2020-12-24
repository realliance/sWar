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
    return new ScoreRecorder(new RandomBot());
  }, "RandomBot");

  RegisterController([](){
    return new ScoreRecorder(new HighBot());
  }, "HighBot");

  RegisterController([](){
    return new ScoreRecorder(new DuelingBot());
  }, "DuelingBot");

  RegisterController([](){
    return new ScoreRecorder(new HighClassBot());
  }, "HighClassBot");

  RegisterController([](){
    return new ScoreRecorder(new LowBot());
  }, "LowBot");

  RegisterController([](){
    return new ScoreRecorder(new RandomBot());
  }, "RandomBot");

  const std::vector<std::string> players = {"RandomBot", "HighBot", "LowBot", "RandomBot", "HighClassBot","DuelingBot"};
  const int playerIterations = (players.size()*(players.size()-1))/2;
  int cnt = 0;

  const int iterations = 10000;
  for(size_t i = 0; i < players.size(); i++){
    for(size_t j = i+1; j < players.size(); j++){
      if(i == j){ continue; }
      for(int k = 0; k < iterations; k++){
        if(k % (iterations/100) == 0){
          std::cout << "\33[2K\r" << cnt << "/" << playerIterations << ": " << k << "/" << iterations << std::flush;
        }
        sWar::StartGame(GameSettings{
          /* seatControllers: */ {players[i],players[j]},
          /* seed: */ 0,
          /* decks: */ 1,
          /* handsize: */ 3,
          /* shuffleWinnings: */ true
        }, /* async: */ false);
      }
      cnt++;
    }
  }

  std::cout << "\33[2K\rGames: " << cnt << std::endl;
  std::cout << "Iterations: " << iterations << std::endl;
  std::cout << std::endl;

  std::vector<std::pair<std::string,int>> wins(ScoreRecorder::Wins.begin(), ScoreRecorder::Wins.end());
  std::sort(wins.begin(), wins.end(), [](std::pair<std::string,int> a, std::pair<std::string,int> b) {
    return a.second > b.second;
  });
  for(const auto & [playerName,wins] : wins){
    std::cout << playerName << ": " << wins << std::endl;
  }

  return 0;
}
