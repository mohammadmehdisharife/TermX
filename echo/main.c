#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 4) {
        fprintf(stderr, "Usage: echo <string> or echo <string> > <file_name>\n");
        return 1;
    }

    if (argc == 2) {
        printf("%s\n", argv[1]);
        return 0;
    } else if (argc == 4 && strcmp(argv[2], ">") == 0) {
        FILE *file = fopen(argv[3], "w");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        fprintf(file, "%s\n", argv[1]);
        fclose(file);
        return 0;
    }

    fprintf(stderr, "Invalid command.\n");
    return 1;
}
