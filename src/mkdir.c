#include <stdio.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
  if (argc != 2) {
    perror("Usage: mkdir <file_name>");
  }
  const char *dir_name = argv[1];

  if (mkdir(dir_name, 0777) == 0) {
      printf("Directory %s created successfully.\n", dir_name);
  } else {
      perror("creating directory");
  }

  return 0;
}
