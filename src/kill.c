#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  int pid;

  pid = fork();
  if (pid==0) {
    int i;
    for (i=1; i<1000000; i++) {
      printf ("%c", 'H');
      if ((i%60)==0) printf ("\n");
    }
    exit(33);
  } else {
    int result, status;
    char c;
    scanf("%c", &c);
    result = kill(pid, SIGKILL);
    printf ("[P] SIGKILL sent to pid=%d with result=%d\n", pid, result);
    result = wait(&status);
    printf("[P] pid=%d finished with HIGH(status)=%d and LOW(status)=%d\n", result, _HIGH(status), _LOW(status));
  }

  return 0;
}
