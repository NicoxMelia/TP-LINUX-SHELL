#include "functions.h"


void printTitle(char *title){
    for(int i=0; i<20; i++){
        printf("-");
    }
    printf("%s",title);
    for(int i=0; i<20; i++){
        printf("-");
    }
    printf("\n");
}

char* printLine(char *buffer){
    return strdup(strstr(buffer, ":") + 2);
}

bool verifyStr(char buffer[], char *tag){
    return strstr(buffer, tag) != NULL;
}

void printClosedKey(bool json){
    if(json) printf("}\n");
}