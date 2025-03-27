#include <stdio.h>

int main(int argc,char *argv[]) {
	if (argc != 2){
		fprintf(stderr, "Usage: cat <file_name>\n");
		return 0;
	}
	FILE *file;
	int c;
	file = fopen(argv[1],"r");
	if (file == NULL){
		perror("cannot open file");
		return 1;
	}
	while((c = fgetc(file)) != EOF)
		putchar(c);
	
	fclose(file);
	return 0;
}
