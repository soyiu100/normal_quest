// needed for printing
#include <stdio.h>
// needed for string moving operations
#include <string.h>
// needed for (m/c)alloc
#include <stdlib.h>
// needed for converting some characters to lower-case
#include <ctype.h>

#include "main.h"
#include "rand_gen.h"
#include "assets.h"

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
    const char* CHEAT[7] = { "Don't try to weasel your way out of this, m8",
	"I too know the dirty tricks you play; don't", "Nice try", "No.",
	"You're in the middle of something, you know", 
	"Pausing is forgivable, however.",
	"This game is road traffic, you can't just park in the middle of it" };
    const char* USR_RET = "Welcome back!";

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
    if (code == SPLASH_ID) { // title "screen" (?)
	result = (char*) malloc(strlen(LOGO)*2 + 5);
    	char brdrPatt[1] = { '|' }; // apparently ISO C++ doesn't like single characters directly assigned to ptrs
        char* brdr = headerBorder(strlen(LOGO), brdrPatt);
 	strcat(brdr, "\n");
	strcpy(result, brdr);
        strcat(result, LOGO);
        strcat(result, "\n");
        strcat(result, brdr);
        return result;
    } else if (code == SPLASH_ID + 1) { // "copyright" info
	result = (char*) malloc(strlen(CPYR[0]) + strlen(CPYR[1]) + 1);
        strcpy(result, CPYR[0]);
	strcat(result, CPYR[1]);
        return result; 
    } else if (code == SPLASH_ID + 2) { // Ctrl-C attempt
 	int msgInd = randInt(6);
	result = (char*) malloc(strlen(CHEAT[msgInd]) + 1);
 	strcpy(result, CHEAT[msgInd]);
        return result;
    } else if (code == SPLASH_ID + 3) { // Ctrl-Z'ed, and returned
	result = (char*) malloc(strlen(USR_RET));
	strcpy(result, USR_RET);
	return result;
    }
}

//
// Returns a random name for a city.
char* generateName() {
    int nameInd = randInt(NAME_SIZE - 1);
    int cityDesInd = randInt(CITYDES_SIZE - 1);
    char* result;
    strcpy(result, NAMES[nameInd]);
    strcat(result, " ");
    strcat(result, CITYDES[cityDesInd]);
    strcat(result, ".\n");
    return result;
}

char* animInfo(anim* headAnim, char* animName, bool retSett[7]) {
    char* notFound = "The name of the animal that you search for does not exist.";
    // since there is no way to have a name larger than 15 characters
    if (strlen(animName) > 15) { 
     	return notFound;
    } else {
    	char* fndRslt;
 	anim* curr = headAnim;
    	while(curr != NULL) {
		//TODO: bitmasking is a hmmmmmm
   	    if (!strcmp(curr->name & 0xFFFFFFFFFFFFFFF0, animName) { // they are the same name
		char hlthInf[3];
		char genTypBrInf[4];
		char ageInf[2];
		char parInf[4];
		char* chldInf;
		char physInf[6];
		char trstInf[2];
		char prnn[2];
  		int mallocAmt = 0;
		int retStrtInd = 0;

                if (!strcmp(curr->name[15], ":") {
 		    prnn[2] = { "She", "Her" };
           	} else {
                    prnn[2] = { "He", "His" };
	    	}


   		if (retSett[0] == 1) { // return info about health
		    hlthInf = { " has ", " health points out of ", " max remaining.\n"};
		    mallocAmt += sizeof(hlthInf) + sizeof(animName);
                } 
   		if (retSett[1] == 1) { // return info about generation/breed/type
		    genTypBrInf = { " is a ", " generation ", " in ", " family.\n" };
	 	    if (retSett[0] == 0) {
  			mallocAmt += sizeof(animName) + sizeof(prnn[1]) + sizeof(genTypeBrInf);
			retStrtInd = 1;
		    } else {
		        mallocAmt += sizeof(prnn[0]) + sizeof(prnn[1]) + sizeof(genTypBrInf);
		    }
                } 
   		if (retSett[2] == 1) { // return info about parents
// TODO: check for indices other than 0 if they have the designated string when looping
		    if (curr->mother == NULL) {
 			parInf[0] = " has no parents.\n";
			if (retSett[0] == 0 && retSett[1] == 0) {
			    mallocAmt += sizeof(animName) + sizeof(parInf[0]);
			} else {
			    mallocAmt += sizeof(prnn[0]) + sizeof(parInf[0]);
			}

		    } else {
			parInf = { " father is a ", ", and ", " mother is a ", ".\n" };
			if (retSett[0] == 0 && retSett[1] == 0) {
 			    mallocAmt += sizeof(animName) + sizeof("'s") + sizeof(prnn[1]) + sizeof(parInf);
			} else {
			    mallocAmt += sizeof(prnn[1])*2 + sizeof(parInf);
			}
    		    }
		} 
		if (retSett[3] == 1) { // return info about any child
   		    if (curr->child == NULL) {
  		        chldInf = " has no child.\n";
		    } else {
			chldInf = " has a child, ";
			char* chldName = curr->child->name;
			mallocAmt += sizeof(chldName);
		    }
		    if (retSett[0] == 0 && retSett[1] == 0 && retSett[2] == 0) {
			mallocAmt += sizeof(animName) + sizeof(chldInf);
		    } else {
 			mallocAmt += sizeof(prnn[1]) + sizeof(chldInf);
		    }
		}
   		if (retSett[4] == 1) { // return information about age
		    ageInf[2] = { " is ", " years old.\n" };
		    // TODO: calculate age implementation
		    if (retSett[0] == 0 && retSett[1] == 0 && retSett[2] == 0 && retSett[3] == 0) {
			mallocAmt += sizeof(animName) + sizeof(ageInf);
		    } else {
			mallocAmt += sizeof(prnn[0]) + sizeof(ageInf) + sizeof(_
		    }
                } 
   		if (retSett[5] == 1) { // physical
    		    physInf[6] = { " has an attack of ", ", a defense of ", " a speed of " };
                } 
		if (retSett[6] == 1) {

		    trstInf[2] = { " is ", " you.\n" };
		    if (retSett[0] == 0 && retSett[1] == 0 && retSett[2] == 0 && retSett[3] == 0
		}
       	  	fndRslt = (char*) malloc(mallocAmt);

       	     } else {
	    	curr = curr->next;
    	     }
    	}
    }
    return notFound;
}

//TODO:
char* getAnimBreed() {


}

//TODO:
char* getAnimType(anim* ref) {
    //TODO: does this even work
    long bitMask = (long) ((int) (~0) << 48);
    print("%x\n", bitMask);
    long type = ref->typBreed & bitMask;
    

}


char* getTrust(anim* ref) {
    short trustAmt = ref->trust;
    if (trustAmt < -32) {
	return "extremely hateful of";
    } else if (trustAmt >= -32 && trustAmt < -16) {
  	return "disliking of";
    } else if (trustAmt >= -16 && trustAmt < 0) {
	return "resisting against";
    } else if (trustAmt >= 0 && trustAmt < 16) {
	return "ambivalent towards";
    } else if (trustAmt >= 16 && trustAmt < 32) {
	return "somewhat trusting of";
    } else if (trustAmt >= 32 && trustAmt < 240) { // TODO: this bound is a little high...?
	return "devoted to";
    }
    return "enamored by";


}
