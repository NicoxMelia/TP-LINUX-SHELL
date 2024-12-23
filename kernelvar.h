#ifndef KERNELVAR_H
#define KERNELVAR_H

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * @param json a param used by these functions to decide how should they display
 *             the information in the console
*/

void getVersion(bool json); //this function displays the kernel version
void getCpuInfo(bool json); //this function displays the user cpu information
void getTime(bool json); //this function shows the time since the OS started
void getFileSystems(bool json); //this function shows supported filesystem by the cpu
void getPartitions(bool json); //this function displays in console partitions with their filesystem
void getCpuName(bool json); //this function shows the cpu name
void getActualTime(bool json); //this function prints the actual time

#endif