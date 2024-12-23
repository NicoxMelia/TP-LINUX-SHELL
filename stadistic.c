#include "stadistic.h"


void getStat(bool json){

    FILE *stat = fopen("/proc/stat", "r");
    char buffer[1024];


    unsigned long long int user, nice, system, idle;

    if (fgets(buffer, sizeof(buffer), stat) != NULL) {
        sscanf(buffer + 4, "%llu %llu %llu %llu", &user, &nice, &system, &idle);
    }
    if(json){
        printf("\n\t\"tiempo de cpu utilizado por usuarios\" : \"%llu\",", user);
        printf("\n\t\"tiempo de cpu utilizado por el sistema\" : \"%llu\",", system);
        printf("\n\t\"tiempo de cpu en estado idle\" : \"%llu\",", idle);
    }else{
        printTitle("Otros datos estadisticos");
        printf("Tiempo de CPU utilizado por usuarios: %llu\n", user);
        printf("Tiempo de CPU utilizado por el sistema: %llu\n", system);
        printf("Tiempo de CPU en estado idle: %llu\n", idle);

    }
    fclose(stat);
}

void getContext(bool json){
    FILE *stat = fopen("/proc/stat", "r");
    char buffer[1024];

    unsigned long long int context;

    while (fgets(buffer, sizeof(buffer), stat) != NULL) {
        if(sscanf(buffer, "ctxt %llu", &context) == true){
            break;
        }
    }

    if(json){
        printf("\n\t\"cantidad de cambios de contexto\" : \"%llu\",", context);
    }else{
        printf("Cantidad de cambios de contexto: %llu\n", context);
    }

    fclose(stat);
}

void getProcess(bool json){
    FILE *stat = fopen("/proc/stat", "r");
    char buffer[1024];

    unsigned long long int process;

    while (fgets(buffer, sizeof(buffer), stat) != NULL) {
        if(sscanf(buffer, "processes %llu", &process) == true){
            break;
        }
    }
    if(json){
        printf("\n\t\"numero de procesos creados desde el inicio del sistema\" : \"%llu\"\n", process);
        printf("}\n");
    }else{
        printf("Número de procesos creados desde el inicio del sistema: %llu\n", process);
    }
    
    fclose(stat);
}