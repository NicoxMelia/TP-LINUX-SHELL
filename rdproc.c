#include "functions.h"
#include "polling.h"
#include "process.h"
#include "kernelvar.h"
#include "stadistic.h"
#include <getopt.h>
#include <unistd.h>


/**
 * the main function
*/
int main(int argc, char* argv[]){

    bool json = false;
    bool s_option = false;
    bool l_option = false;
    bool p_option = false;
    int interval, duration;
    int option;
    int pid;

    
    while ((option = getopt(argc, argv, "sjl:p:")) != -1) {
        //flags given in the console by the user are readed and saved at variables
        switch (option) {
            case 'j':
                json = true;
                printf("{");
                break;
            case 's':
                s_option = true;
                if(l_option || p_option) return -1;
                break;
            case 'l':
                l_option = true;
                if(s_option || p_option) return -1;
                interval = atoi(optarg);
                duration = atoi(argv[optind]);
                break;
            case 'p':
                p_option = true;
                if (l_option || s_option) return -1;
                pid = atoi(optarg);
                break;
            default:
                printf("opcion desconocida\n");
                return 0;
        }
    }


    //in this secction we call all necessary functions to the user
    getCpuInfo(json);
    getVersion(json);
    getTime(json);
    getFileSystems(json);
    getPartitions(json);
    getCpuName(json);
    getActualTime(json);
    if(s_option){
        getStat(json);
        getContext(json);
        getProcess(json);
    }else if(l_option){
        while((duration -= interval) >= 0){
            getRequests(json);
            getMemory(json);
            getAvg(json);
            sleep((unsigned)interval);
            printf("\n\n");
        }
    }else if(p_option){
        getDescriptors(json, pid);
        getFileLimit(json, pid);
    }else{
        printClosedKey(json);
    }

}