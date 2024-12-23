#ifndef STADISTIC_H
#define STADISTIC_H

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getStat(bool json); //this function displays the cpu time used by the users, system and idle process
void getContext(bool json); //this funcion shows the context change
void getProcess(bool json); //this function shows the number of process created since OS started


#endif