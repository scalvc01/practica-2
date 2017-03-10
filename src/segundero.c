#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction sa;

void tic (int sig) {}

int main(void) {
  int seconds = 0;

  sa.sa_handler = tic;
  sigaction (SIGALRM, &sa, NULL);
  while(1) {
    seconds++;
    alarm(1);
    pause();
    printf ("%d\n", seconds);
  }

  return 0;
}
