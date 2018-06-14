#include <stdio.h>
#include <string>
#include <windows.h>
// SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), 0x5B);

#include "main.h"
#include "messages.h"
#include "writeto.h"

/*
This class acts as the controller for the program, taking
input and throwing output to the user

*/
#define MAX_STRING_LENGTH (1 << 7)

int main() {
   std::cout << messages(-64);
   std::cout << messages(1);
   while (
/*
   char string[20];
   while (strcmp(string,"quit") != 0) {
     printf("Answer this question:\n");
     scanf(" %128[^\n]", string);
     printf("%s\n", string);
   }
*/
   
}
