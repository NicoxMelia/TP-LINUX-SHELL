#include "kernelvar.h"

void getVersion(bool json){
    FILE *fileVersion;
    char buffer[1024];

    fileVersion = fopen("/proc/version", "r");
    if(fileVersion != NULL){
        if(fgets(buffer, sizeof(buffer), fileVersion) != NULL){
            if(json){
                printf("\t\"version del kernel\": \"%s\",", strtok(buffer, "\n"));
            }else{
                printTitle("Version del kernel:");
                printf("%s", buffer);
            }
        }else{
            printf("ERROR AL LEER LA VERSION DEL KERNEL!");
        }
    }
    fclose(fileVersion);
}

void getCpuInfo(bool json){
    FILE * fileCpu;
    char buffer[1024];
    int counter = 0;

    fileCpu = fopen("/proc/cpuinfo", "r");

    if(fileCpu != NULL){
        while(fgets(buffer, sizeof(buffer), fileCpu) != NULL){
            if(counter == 3) break;
            if(verifyStr(buffer, "model name")){
                if(json){
                    printf("\n\t\"modelo del cpu\" : \"%s\",\n", strtok(printLine(buffer), "\n"));
                }else{
                    printTitle("Modelo del CPU:");
                    // printf(strdup(strstr(buffer, ":") + 2));
                    printf("%s", printLine(buffer));
                }
                counter++;
            }else if(verifyStr(buffer,"cpu cores")){
                if(json){
                    printf("\t\"numero de nucleos\" : \"%s\",\n", strtok(printLine(buffer), "\n"));
                }else{
                    printTitle("Numero de nucleos:");
                    // printf(strdup(strstr(buffer, ":") + 2));
                    printf("%s", printLine(buffer));
                }
                counter++;
            }else if(verifyStr(buffer, "cache size")){
                if(json){
                    printf("\t\"cache\" : \"%s\",\n", strtok(printLine(buffer), "\n"));
                }else{
                    printTitle("Cache");
                    printf("%s", printLine(buffer));
                }
                counter++;
            }
        }
    }
    fclose(fileCpu);
}

void getTime(bool json){
    FILE *time = fopen("/proc/uptime", "r");
    char buffer[1024];
    int timeReaded;
    int dias, horas, minutos, segundos;

    if(fgets(buffer, sizeof(buffer), time) != NULL){
        sscanf(buffer, "%i", &timeReaded);
        dias = timeReaded / 86400;
        timeReaded %= 86400;
        horas = timeReaded / 3600;
        timeReaded %= 3600;
        minutos = timeReaded / 60;
        segundos = timeReaded % 60;

        if(json){
            printf("\n\t\"tiempo transcurrido\" : \"%i dias %i horas %i minutos %i segundos\",\n", dias, horas, minutos, segundos);
        }else{
            printTitle("Tiempo transcurrido:");
            printf("%i dias\n%i horas\n%i minutos\n%i segundos\n", dias, horas, minutos, segundos);
        }

    }
}

void getFileSystems(bool json){
    FILE *fileSys = fopen("/proc/filesystems", "r");
    char buffer[1024];

    if(json){
        printf("\t\"filesystems soportados por el kernel\" : [");
        while(fgets(buffer, sizeof(buffer), fileSys) != NULL){
            char value[1024];
            if(sscanf(buffer, "%*s %s", value) == 1){
                printf("%s, ", strtok(value, "\t\n"));
            }else{
                printf("%s, ", strtok(buffer, "\t\n"));
            }
        }
        printf("]");
    }else{
        printTitle("Filesystems soportados por el kernel:");
        while(fgets(buffer, sizeof(buffer), fileSys) != NULL){
            printf("%s", buffer);
        }
    }
}

void getPartitions(bool json){
    FILE *fileParts = fopen("/proc/mounts", "r");
    char buffer[1024];

    
    if(json){
        printf("\n\t\"particiones del equipo\" : [");
    }else{
        printTitle("Particiones del equipo");
    }

    while (fgets(buffer, sizeof(buffer), fileParts) != NULL) {
        char dispositivo[256];
        char puntoMontaje[256];
        char tipoFileSystem[256];
        char opciones[256];

    
        if (sscanf(buffer, "%s %s %s %s", dispositivo, puntoMontaje, tipoFileSystem, opciones) == 4) {
            if(json){
                printf("\n\t\t\t\t\t{");
                printf("\n\t\t\t\t\t\t\"%s\" : \"%s\"", "dispositivo", dispositivo);
                printf("\n\t\t\t\t\t\t\"%s\" : \"%s\"", "punto de montaje", puntoMontaje);
                printf("\n\t\t\t\t\t\t\"%s\" : \"%s\"", "tipo de filesystem", tipoFileSystem);
                printf("\n\t\t\t\t\t\t\"%s\" : \"%s\"", "ociones", opciones);
                printf("\n\t\t\t\t\t},");
            }else{
                printf("Dispositivo: %s\n", dispositivo);
                printf("Punto de montaje: %s\n", puntoMontaje);
                printf("Tipo de filesystem: %s\n", tipoFileSystem);
                printf("Opciones: %s\n", opciones);
                printf("\n");
            }
        }
    }
    if(json){
        printf("\n\t\t\t\t],");
    }
}

void getCpuName(bool json){
    FILE *nameCpu = fopen("/proc/sys/kernel/hostname", "r");
    char buffer[1024];

    if(fgets(buffer, sizeof(buffer), nameCpu) != NULL){
        if(json){
            printf("\n\t\"nombre del equipo\" : \"%s\",", strtok(buffer, "\n"));
        }else{
            printTitle("NOMBRE DEL EQUIPO");
            printf("%s", buffer);
        }
    }
}

void getActualTime(bool json){
    FILE *actualTime = fopen("/proc/uptime", "r");
    time_t currentTime;
    char buffer[1024];
    time_t uptime;

    if(fgets(buffer, sizeof(buffer), actualTime) != NULL){
        uptime = (time_t) strtod(buffer, NULL);
        currentTime = time(NULL) - uptime;
        if(json){
            printf("\n\t\"fecha y hora actual del sistema\" : \"%s\",\n", strtok(ctime(&currentTime), "\n"));
        }else{
            printTitle("Fecha y hora actual del sistema");
            printf("%s", ctime(&currentTime));
        }
        
    }
}