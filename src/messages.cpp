#include <stdio.h>
#include <string>
// #include "main.h"  // non-test line
#include "test.h"  // testing line
#include "rand_gen.h"

/*
This contains most of the view in the program, returning
strings to the control.
*/

// anonymous namespace to hide all messages to implementation
namespace {
    const std::string FIRST_TIME = "hey! welcome lol";
    const std::string CPYR[2] = {"all source codes created and belong to me;", 
        "plz don't take"}; 
    const std::string LOGO = "normal quost";


    const int NAME_SIZE = 3;
    const int CITYDES_SIZE = 3;

    // these article(s) are incomplete. you can help by expanding it.
    const std::string NAMES[NAME_SIZE] = { "Butter", "Quarter", "Beta" };
    const std::string CITYDES[CITYDES_SIZE] = { "Town", "City", "Ville" };
};



std::string messages(int code) {
    if (code == SPLASH_ID) {
        return LOGO + "\n";
    } else if (code == SPLASH_ID + 1) {
        return CPYR[0] + CPYR[1] + "\n"; // TODO: replace all these with unmodif. str in namesp.
    } else {
        return "oops";
    }
}

//
// Returns a random name for a city.
std::string generateName() {
    int nameInd = randInt(NAME_SIZE);
    int cityDesInd = randInt(CITYDES_SIZE);
    return NAMES[nameInd] + " " + CITYDES[cityDesInd];
}
