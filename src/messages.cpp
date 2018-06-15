#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "rand_gen.h"

/*
This contains most of the view in the program, returning
strings to the control.
*/

// anonymous namespace to hide all messages to implementation
namespace {

    const char* FIRST_TIME = "hey! welcome lol";
    const char* CPYR[2] = {"all source codes created and belong to me;",
	"plz don't take"}; 
    const char* LOGO = "| Normal Quest |";


    const int NAME_SIZE = 7;
    const int CITYDES_SIZE = 3;

    // these article(s) are incomplete. you can help by expanding it.
    const char* NAMES[NAME_SIZE] = { "Butter", "Quarter", "Beta",
        "Alpha", "Testing", "Squirrel", "Acorn" };
    const char* CITYDES[CITYDES_SIZE] = { "Town", "City", "Ville" };
};


// scope is top to bottom, so it's blind otherwise
// TODO: this can be private boyo
char* headerBorder(int strLeng, char* bordType) {
     int i;
     // create space to allocate the string
     char* hdr = (char*) malloc(strLeng);
     // something has to be copied first, or the /0 will be overwritten
     strcpy(hdr, bordType);
     for (i = 1; i < strLeng; i++) {
        strcat(hdr, bordType);
     }
     return hdr;
}


char* messGen(int code) {
    char* result;
    if (code == SPLASH_ID) {
	result = (char*) malloc(strlen(LOGO)*2 + 5);
    	char brdrPatt[1] = { '|' }; // apparently ISO C++ doesn't like single characters directly assigned to ptrs
        char* brdr = headerBorder(strlen(LOGO), brdrPatt);
 	strcat(brdr, "\n");
	strcpy(result, brdr);
        strcat(result, LOGO);
        strcat(result, "\n");
        strcat(result, brdr);
        return result;
    } else if (code == SPLASH_ID + 1) {
	result = (char*) malloc(strlen(CPYR[0]) + strlen(CPYR[1]) + 3);
        strcat(result, CPYR[0]);
	strcat(result, CPYR[1]);
        strcat(result, "\n");
        return result; 
    } else {
        return "oops"; // TODO: reip
    }
}

//
// Returns a random name for a city.
char* generateName() {
    int nameInd = randInt(NAME_SIZE - 1);
    int cityDesInd = randInt(CITYDES_SIZE - 1);
    char* result;
    strcat(result, NAMES[nameInd]);
    strcat(result, " ");
    strcat(result, CITYDES[cityDesInd]);
    strcat(result, ".\n");
    return result;
}


