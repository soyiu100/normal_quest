//////////////////////////////////////
//// this is a mock main.cpp file ////
//////////////////////////////////////

#include <iostream>
#include <string>
#include "messages.h"
#include "test4.h"
#include "rand_gen.h"
#include "assets.h"

int main() {
  std::cout << messages(SPLASH_ID);
  std::cout << messages(SPLASH_ID + 1);
  loc* start = createLandmass();
  printf("You are in %s\n", getLocName(start));
  // std::cout << randBool(-0.5);
  return 0;
}
