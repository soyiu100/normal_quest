//////////////////////////////////////
//// this is a mock main.cpp file ////
//////////////////////////////////////

#include <iostream>
#include <string>
#include "messages.h"
#include "test.h"
#include "rand_gen.h"
#include "assets.h"

int main() {
  std::cout << messages(SPLASH_ID);
  std::cout << messages(SPLASH_ID + 1);
  createLandmass();
  // std::cout << randBool(-0.5);
  return 0;
}
