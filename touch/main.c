#include <stdio.h>

int main(int argc,char *argv[]) {
	if (argc != 2){
		perror("touch <file_name>");
		return 1;
	}
	fopen(argv[1],"w");
	return 0;
}
