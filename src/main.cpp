#include <stdio.h>
#include <string.h>
#include <string>
#include "messages.h"
#include "writeto.h"


#define MAX_STRING_LENGTH (1 << 7)

struct Animal {
  int generation;
  int health;
  int exp; // (avg age of that animal - exp)/constant = age;
  int trust;
  char breed[16];
  char type[8]; // e.g. bird, cow, dog etc.
  struct Animal* mother;
  struct Animal* father;
  // struct Animal* child; // in case we want to override the number of children

};
typedef struct Animal anim;

int main() {
   std::cout << messages(-4);
   std::cout << messages(-3);
   while
/*
   char string[20];
   while (strcmp(string,"quit") != 0) {
     printf("Answer this question:\n");
     scanf(" %128[^\n]", string);
     printf("%s\n", string);
   }
*/
   
}
