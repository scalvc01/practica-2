#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
  int pid = fork();
  if (pid==0) {
    printf("[H] ppid = %5d, pid = %5d\n", getppid(), getpid());
    exit(33);
  }
  else {
    int p, status;
    printf("[P] ppid = %5d, pid = %5d, H = %5d\n", getppid(), getpid(), pid);
    p = waitpid(pid, &status, 0);
    printf("[P] el proceso pid=%d acaba de terminar con esado %d\n", p, status);
  }
  
  return 0;
}