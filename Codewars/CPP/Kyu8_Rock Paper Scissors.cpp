std::string rps(const std::string& p1, const std::string& p2)
{
  int p1_won;
  if (p1 == "scissors") {
    if (p2 == "paper"){
      p1_won = 1;
    } else if (p2 == "scissors") { 
      p1_won = 0;
    } else {
      p1_won = -1;
    }
  } else if (p1 == "paper") {
    if (p2 == "rock"){
      p1_won = 1;
    } else if (p2 == "paper") { 
      p1_won = 0;
    } else {
      p1_won = -1;
    }
  } else if (p1 == "rock") {
    if (p2 == "scissors"){
      p1_won = 1;
    } else if (p2 == "rock") { 
      p1_won = 0;
    } else {
      p1_won = -1;
    }
  }
  if (p1_won == 1) {
    return "Player 1 won!";
  } else if (p1_won == 0) {
    return "Draw!";
  } else {
    return "Player 2 won!";
  }
}
