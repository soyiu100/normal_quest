#include <iostream>
#include "messages.h"

/*
This is a model for objects that appear in game.
*/


struct Animal {
    int generation;
    int health;
    int exp; // (avg age of that animal - exp)/constant = age;
    int trust;
    char breed[16];
    char type[8]; // e.g. bird, cow, dog etc.
    struct Animal* mother;
    struct Animal* father;
    struct Animal* child; 
};
typedef struct Animal anim; 


struct Character {
    int money;
    anim animals[8];
}; 
typedef struct Character charc_t;

struct MainCharacter : Character {
    char gnd;
    int rep;
    item bag[128];
    
};
typedef struct MainCharacter mc;


struct Location {
    /* Each character will represent a specific NPC, and 
    based on what the character is, main() will handle the
    outcome. There can be a max of 7 in a location. */
    char* name;
    char npcs[7]; 
    bool outdoors; // 0 for outdoors, 1 for indoors
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
    loc* l = calloc(1, sizeof(loc));
    printf("%d", sizeof(loc)); // to make sure there is no frag
    l->name = generateName(
}
