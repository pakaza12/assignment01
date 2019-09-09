/**
* Parker Zach
* 09/04/19
* Assignment 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double winPercentage1, winPercentage2, winPercentage3, winPercentage4;
  int runsScored, runsAllowed, gamesPlayed, gamesWon;
  double p1 = 2;
  double p2 = 1.83;
  double p3, p4;
  //Declared variables and types

  runsScored = atoi(argv[1]);
  runsAllowed = atoi(argv[2]);
  gamesPlayed = atoi(argv[3]);
  gamesWon = atoi(argv[4]);
  //This makes the user enter the input in the terminal as a command line argument

  if (runsScored < 0 || runsScored > 2147483647) {
    printf("Invalid input(s)");
    return 0; }
  if (runsAllowed < 0 || runsAllowed > 2147483647) {
    printf("Invalid input(s)");
    return 0; }
  if (gamesPlayed < 0 || gamesPlayed > 2147483647) {
    printf("Invalid input(s)");
    return 0; }
  if (gamesWon < 0 || gamesWon > 2147483647) {
    printf("Invalid input(s)");
    return 0; }
  //This is a basic check to make sure none of the values are less than 0 or greater than 2,147,483,647

  p3 = (1.5 * log10(((float) runsScored + runsAllowed) / gamesPlayed)) + 0.45;
  p4 = pow((((float) runsScored + runsAllowed) / gamesPlayed), 0.287);
  //These quations calculate the needed p values

  winPercentage1 = (pow(runsScored, p1)) / (pow(runsScored, p1) + pow(runsAllowed, p1)) * 100;
  winPercentage2 = (pow(runsScored, p2)) / (pow(runsScored, p2) + pow(runsAllowed, p2)) * 100;
  winPercentage3 = (pow(runsScored, p3)) / (pow(runsScored, p3) + pow(runsAllowed, p3)) * 100;
  winPercentage4 = (pow(runsScored, p4)) / (pow(runsScored, p4) + pow(runsAllowed, p4)) * 100;
  //This calculates the win percentages 1-4

  double predictedWins1 = winPercentage1 / 100 * gamesPlayed;
  double predictedWins2 = winPercentage2 / 100 * gamesPlayed;
  double predictedWins3 = winPercentage3 / 100 * gamesPlayed;
  double predictedWins4 = winPercentage4 / 100 * gamesPlayed;
  //This calculates all of the predicted wins

  double predictedLoss1 = (1 - (winPercentage1 / 100)) * gamesPlayed;
  double predictedLoss2 = (1 - (winPercentage2 / 100)) * gamesPlayed;
  double predictedLoss3 = (1 - (winPercentage3 / 100)) * gamesPlayed;
  double predictedLoss4 = (1 - (winPercentage4 / 100)) * gamesPlayed;
  //This calculates all of the predicted losses

  double error1 = abs(round(predictedWins1 - gamesWon));
  double error2 = abs(round(predictedWins2 - gamesWon));
  double error3 = abs(round(predictedWins3 - gamesWon));
  double error4 = abs(round(predictedWins4 - gamesWon));
  //This calculates the error between predicted wins and actual wins

  printf("p value  Win Percentage  Predicted wins  Predicted Loss  Error\n");
  printf("%.2f     %.2f           %2.0f             %2.0f              %2.0f\n", p1, winPercentage1, predictedWins1, predictedLoss1, error1);
  printf("%.2f     %.2f           %2.0f             %2.0f              %2.0f\n", p2, winPercentage2, predictedWins2, predictedLoss2, error2);
  printf("%.2f     %.2f           %2.0f             %2.0f              %2.0f\n", p3, winPercentage3, predictedWins3, predictedLoss3, error3);
  printf("%.2f     %.2f           %2.0f             %2.0f              %2.0f\n", p4, winPercentage4, predictedWins4, predictedLoss4, error4);
  //This prints out all of the information in a table

return 0;
}
