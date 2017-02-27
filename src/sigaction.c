#include <stdio.h>
#include <signal.h>

void handler (int sig) {
  printf ("SIGINT received\n");
}

int main(void) {
  struct sigaction sa;

  sa.sa_handler = handler;

  sigaction (SIGINT, &sa, NULL);

  while(1) {}

  return 0;
}
