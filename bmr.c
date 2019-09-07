/**
* Parker Zach
* 09/06/19
* Assignment 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double gender, weight, height, age, bmr;
  //This declares the variables and types

  printf("Are you female[1] or male[2]: ");
  scanf("%lf", &gender);
  gender = round(gender);
  if (gender < 1 || gender > 2) {
    printf("Error: Invalid Gender\n");
    return 0; }
  //This code prompts the user to enter a 1 or 2, if they don't the program stops

  printf("How much do you weight in kg: ");
  scanf("%lf", &weight);
  if (weight <= 0 || weight > 2147483647) {
    printf("Bad Input(s)\n");
    return 0; }
  //This code prompts the user to enter a weight within the restraints

  printf("How tall are you in cm: ");
  scanf("%lf", &height);
  if (height <= 0 || height > 2147483647) {
    printf("Bad Input(s)\n");
    return 0; }
  //This code prompts the user to enter a height within the restraints

  printf("How old are you in years: ");
  scanf("%lf", &age);
  if (age <= 0 || age > 2147483647) {
    printf("Bad Input(s)\n");
    return 0; }
  //This prompts the user to enter in a valid age

  if (gender == 1) {
    bmr = 655.1 + 9.6 * weight + 1.8 * height - 4.7 * age; }
  if (gender == 2) {
    bmr = 66.47 + 13.7 * weight + 5 * height - 6.8 * age; }
  //The first equation calculates a female BMR while the second calculates a male BMR

  printf("Subject's BMR: %.2f kCal/day", bmr);
  //The last output showing the individual's BMR

return 0;
}
