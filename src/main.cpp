#include <iostream>
#include <string.h>
#include <signal.h>
// This is a Windows thing so it doesn't work on Ubuntu
// #include <windows.h>
// SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x5B);

#include "main.h"
#include "strhandl.h"
#include "rand_gen.h"
#include "assets.h"
#include "writeto.h"

/*
This class acts as the controller for the program, taking
input and throwing output to the user.
*/

#define EXT_STR "quit"
#define EXT_BLK "quitf"

namespace {
    bool saveable;
}


void exitAttempt(int signal) {
    if (signal == SIGINT) {
	if (saveable == 0)
	    printf("\r%s\n", messGen(SPLASH_ID + 2));
    } else if (signal == SIGCONT) {
        printf("\r%s\n", messGen(SPLASH_ID + 3));
    }
}


// Updates the autosave, saveability state, and force exit ability
void idleStateUpdate() {
    signal(SIGCONT, exitAttempt);
    if (saveable == 0) {
	/* restrict Ctrl-C exits where possible, since that could
	be potentially game-breaking */
 	signal(SIGINT, exitAttempt);
        //
    } else {
	signal(SIGINT, SIG_DFL);
   	// encode(auto); // or something like that
    }
}

int main() {
    printf("%d\n", SIGINT);
    printf("%s\n", messGen(SPLASH_ID));
    printf("%s\n", messGen(SPLASH_ID + 1));
    char inStr[128];
    /* 
    1s that say to return to the user. By default, all 
    properties of the animal are given to the user, but 
    there will be an option to return less or more info.
    All 0s and 1s correlate in the code in the order
    that is provided:
[ health/maxHealth | generation/type/breed | parent | child | age | physical | trust ]
    */
    /* 
    In the case that the user wants to change properties
    that are returned, the user will type in a string
    of the property that they want. If it is not found, 
    then the console will say so.
    There will be a option for the user to list the options
    that they can turn off.
    */
    // TODO: save this state in an autosave or whatnot
    // TODO: also should this be in a namespace?
    bool[7] animRetSett;

    saveable = 0; // 1 means you can save or quit

    idleStateUpdate();

    while (strcmp(inStr, EXT_STR)) {
        printf("Answer this question:\n");
        scanf(" %128[^\n]", inStr);
        if (saveable == 0 && !strcmp(inStr, EXT_STR))
	    strcpy(inStr, EXT_BLK);
	printf("%s\n", inStr);
        if (!strcmp(inStr, "hackerman"))
      	    saveable = 1;
    }

   
}



