#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {

  if (argc != 2) {
	  fprintf(stderr, "Using: program [filename]\n");
	  return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
	  perror("open file failed");
	  return 1;
  }

  ssize_t bytes_read, bytes_write;
  char buffer[BUF_SIZE];

  while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
	  bytes_write = write(STDOUT_FILENO, buffer, bytes_read);
	  if (bytes_read != bytes_write) {
		  perror("write file failed");
		  return 1;
	  }
  }

  if (bytes_read < 0) {
    perror("read failed");
    return 1;
  }

  close(fd);
  return 0;
}
