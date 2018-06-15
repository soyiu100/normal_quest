#include <iostream>
#include <string.h>
// This is a Windows thing so it doesn't even work on Ubuntu
// #include <windows.h>
// SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x5B);

#include "main.h"
#include "messages.h"
#include "rand_gen.h"
#include "assets.h"
#include "writeto.h"

/*
This class acts as the controller for the program, taking
input and throwing output to the user

*/

int main() {
   printf("%s", messGen(SPLASH_ID));
   printf("%s", messGen(SPLASH_ID + 1));
   char string[20];
   while (strcmp(string,"quit") != 0) {
     printf("Answer this question:\n");
     scanf(" %128[^\n]", string);
     printf("%s\n", string);
   }

   
}
