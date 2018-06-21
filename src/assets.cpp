#include <string.h>
#include <stdio.h>
#include "strhandl.h"

/*
This is a model for objects that appear in game.
*/
// TODO: do not share setters, getters, constructors etc., and 
// make all struct members private

struct Animal {
    char name[16];

    short health;
    short maxHealth;
    short generation;
    short atk;
    short defense;
    short speed;
    short trust;
    short exp; // (avg age of that animal - exp)/constant = age;

    long typBreed; // 16:48 bit ratio; type to breed

    struct Animal* mother;
    struct Animal* father;
    struct Animal* child;

    struct Animal* prev;
    struct Animal* next;
};
typedef struct Animal anim; 

// TODO: implement
/*
struct Item {
  map<quality, how much> (eg. heal, 40)
};
typedef struct Item item;
*/

// TODO: reorganize the internals of these structs, geez
struct Character {
    int money;
    anim* headAnim;
}; 
typedef struct Character charc;

struct MainCharacter : Character {
    char gnd;
    char name[15];
    int rep;
    // TODO: implement item; commented out for testing purposes
    // item bag[128];
    
};
typedef struct MainCharacter mc;


struct Location {
    /* Each character will represent a specific NPC, and 
    based on what the character is, main() will handle the
    outcome. There can be a max of 7 in a location. */
    char name[24];
    charc npcs[7]; 
    bool locType; // 0 for road, 1 for city
    char buildings[8]; 
    struct Location* next;
    struct Location* prev;
};
typedef struct Location loc;

struct Landmass {
    loc startLoc;
};
typedef struct Landmass land;


//TODO: test method; if this works, multiply
//TODO: create a new Landmass, and let test.cpp print out all names
//TODO: if that works, test and develop a saving feature
loc* createLandmass() {
    // TODO: for now, just create one location dumm
    loc* l = (loc*) calloc(1, sizeof(loc));
    printf("%d\n", sizeof(loc)); // to make sure there is no frag
    // above expected: 56; if not, frag or bad math
    char* cityName = generateName();
    strcpy(l->name, cityName);
    printf("%s\n", l->name);
    // TODO: most implementation is incomplete here lol
    return l;
}

char* getLocName(loc* location) {
   return location->name;
}




// TODO: delete or comment out after testing
mc* arbitrMCBuild() {
    mc* mch = (mc*) calloc(1, sizeof(loc));
    printf("%d\n", sizeof(anim));
    anim* startingAnim = (anim*) calloc(1, sizeof(anim));
    mch->headAnim = startingAnim;
    mch->headAnim->
}

void reverseAnimOrder() {


}

void switchTwoAnims() {

}



charc* addAnim(charc* chr, anim* newAnim) {
    anim* curr = chr->headAnim;
    int i = 1;
    while(curr->next != NULL) {
	curr = curr->next;
        i++;
    }
    curr->next = newAnim;
    // TODO: is this right??? e.g. do you have to link the
    // anim* chr back to the chr->headAnim?
    return chr;
}
