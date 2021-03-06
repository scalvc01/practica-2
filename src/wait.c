#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid==0)
    printf("[H] ppid = %5d, pid = %5d\n", getppid(), getpid());
  else {
    int p, status;
    printf("[P] ppid = %5d, pid = %5d, H = %5d\n", getppid(), getpid(), pid);
    p = wait(&status);
    printf("[P] el proceso pid=%d acaba de terminar con estado %d\n", p, status);
  }
  
  return 0;
}