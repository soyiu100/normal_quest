#include <stdio.h>
#include <string>

namespace msgs {
    const std::string FIRST_TIME = "lmao check out this meme";
    const std::string LOGO = "normal quost";
    const int SPLASH_ID = -4;
};

using namespace msgs;

std::string messages(int code) {
  if (code == SPLASH_ID) {
     return LOGO;
  } else if (code == SPLASH_ID + 2) {
     return "lol";
  } else {
     return "oops";
  }
}

