#include "process.h"


void getDescriptors(bool json, int pid){
    char pid_path[256];
    snprintf(pid_path, sizeof(pid_path), "/proc/%d/fd/", pid);

    DIR *descriptor_dir = opendir(pid_path);
    struct dirent *entry;
    
    while ((entry = readdir(descriptor_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fd_path[1024];
            snprintf(fd_path, sizeof(fd_path), "%s%s", pid_path, entry->d_name);

            char link_path[256];
            ssize_t link_size = readlink(fd_path, link_path, sizeof(link_path) - 1);
            if (link_size != -1) {
                link_path[link_size] = '\0';
                if(json){
                    printf("\"Descriptor de archivo %s\" : \"%s\"\n", entry->d_name, link_path);
                }else{
                    printf("Descriptor de archivo %s : %s\n", entry->d_name, link_path);
                }
            }
        }
    }

    closedir(descriptor_dir);

}

void getFileLimit(bool json, int pid){
    char limits_path[256];
    snprintf(limits_path, sizeof(limits_path), "/proc/%d/limits", pid);

    FILE *file = fopen(limits_path, "r");
    char line[256];

    if(json){
        printf("\n\t\"Límites de archivos abiertos para el proceso %d\":", pid);
    }else{
        printf("Límites de archivos abiertos para el proceso %d:\n", pid);        
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if(json){
            printf("\"%s\"", line);
        }else{
            printf("%s", line);
        }
    }
    
}