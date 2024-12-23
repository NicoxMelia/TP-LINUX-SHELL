#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


/**
 * @param pid represents the process identifier
*/

void getDescriptors(bool json, int pid); //this function shows the file descriptors available to a given process
void getFileLimit(bool json, int pid); //this function shows the available process's file limits 



#endif