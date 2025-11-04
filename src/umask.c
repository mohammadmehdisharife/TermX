#include <stdio.h>
#include <sys/stat.h>

int main() {
	mode_t mask = umask(0077);
	umask(mask);
	printf("%04o \n",mask);
	return 0;
}
