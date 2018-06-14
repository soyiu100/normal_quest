#include <stdio.h>
#include <string>
// #include "main.h"  // non-test line
#include "test.h"  // testing line

/*
This contains most of the control in the program, returning
strings in the 
*/

// anonymous namespace to hide all messages to implementation
namespace {
    const std::string FIRST_TIME = "lmao check out this meme";
    const std::string CPYR = "all source codes created and" 
     + "belong to me; plz don't take"; 
    const std::string LOGO = "normal quost";


    // this article is incomplete. you can help by expanding it.
    const std::string NAMES[3] = { "Butter", "Quarter", "Beta" }
};



std::string messages(int code) {
    if (code == SPLASH_ID) {
        return LOGO;
    } else if (code == SPLASH_ID + 1) {
        return CPYR; // TODO: replace all these with unmodif. str in namesp.
    } else {
        return "oops";
    }
}

std::string generateName(bool locType) {


}
