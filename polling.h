#ifndef POLLING_H
#define POLLING_H
#include <stdio.h>
#include <stdbool.h>

/**
 * @param json a param used to decide how these functions have to display the information
 *             in the console
*/

void getRequests(bool json); //this function displays the number of request realized to the disk
void getMemory(bool json); //this function displays the numero of memory assigned to the hardware
void getAvg(bool json); //this function shows the last minute load average


#endif