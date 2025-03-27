#include <stdio.h>

int main(int argc,char *argv[]) {
	if (argc != 2){
		perror("cat <file_name>");
		return 0;
	}
	FILE *file;
	char c;
	file = fopen(argv[1],"r");
	if (file == NULL){
		perror("can not open file");
		return 1;
	}
	while((c = fgetc(file)) != EOF)
		putchar(c);
	return 0;
}
