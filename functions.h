#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * all of these functions are used to give a different format to the display in console
 * these functions aren't used to display a JSON format.
 * JSON format is displayed by the rest of the functions
*/

void printTitle(char *title);
char* printLine(char *buffer);
bool verifyStr(char buffer[], char *tag);
void printClosedKey(bool json);


#endif