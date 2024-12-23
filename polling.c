#include "polling.h"


void getRequests(bool json){
    FILE *peticion = fopen("/proc/diskstats", "r");
    char buffer[1024];

    int p_read, p_write, total = 0;

    while(fgets(buffer, sizeof(buffer), peticion)!= NULL){
        if (sscanf(buffer, "%*d %*d sd%*s %i %*d %*d %*d %i %*d %*d %*d %*d %*d %*d", &p_read, &p_write) == 2) {
            total += p_read + p_write;
        }
    }

    if(json){
        printf("\n\t\"numero de peticiones a disco realizadas\" : \"%i\",", total);
    }else{
        printf("Numero de peticiones a disco realizadas: %i\n", total);
    }

    fclose(peticion);
}

void getMemory(bool json){
    FILE *memory = fopen("/proc/meminfo", "r");
    char buffer[1024];

    unsigned long int memTotal = 0, memAvailable = 0;

    while(fgets(buffer, sizeof(buffer), memory) != NULL){
        sscanf(buffer, "MemTotal: %lu\n", &memTotal);
        sscanf(buffer, "MemAvailable: %lu\n", &memAvailable);
    }

    if(json){
        printf("\n\t\"Memoria disponible / total\" : \"%lu / %lu\"\n", memAvailable, memTotal);
    }else{
        printf("Memoria disponible / total : %lu / %lu\n", memAvailable, memTotal);
    }
    fclose(memory);
}

void getAvg(bool json){
    FILE *avg = fopen("/proc/loadavg", "r");
    char buffer[1024];

    double average;

    if(fgets(buffer, sizeof(buffer), avg) != NULL){
        sscanf(buffer, "%lf", &average);
    }

    if(json){
        printf("\t\"Promedio de carga en el ultimo minuto\" : \"%lf\"\n", average);
    }else{
        printf("Promedio de carga en el ultimo minuto: %lf\n", average);
    }

    fclose(avg);
}

