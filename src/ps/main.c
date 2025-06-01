#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    FILE *fp;
    char path[256], line[256];
    int pid;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid = atoi(entry->d_name); 

            snprintf(path, sizeof(path), "/proc/%d/status", pid);
            fp = fopen(path, "r");
            if (fp == NULL) {
                continue;
            }

           
            while (fgets(line, sizeof(line), fp) != NULL) {
                if (strncmp(line, "Name:", 5) == 0) {
                    printf("PID: %d, Name: %s", pid, line + 6);
                    break;
                }
            }
            fclose(fp);
        }
    }

    closedir(dir);
    return 0;
}

