#include <stdio.h>
#include <unistd.h>

int main()
{
  char cwd[1024];
  if (getcwd(cwd,sizeof(cwd))){
    printf("%s\n", cwd);
  } else {
    perror("pwd");
    return 1;
  }
  return 0;
}
