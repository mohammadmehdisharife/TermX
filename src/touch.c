#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename> [filename] ...\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		int fd = creat(argv[i], 0644); // S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
    	if (fd == -1) {
    	    perror("creating file");
    	    return 1;
    	}
    	close(fd);
	}

	return 0;
}
