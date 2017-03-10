#include <stdio.h>
#include <signal.h>

struct sigaction sa, saa;

void handler (int sig) {
  printf ("SIGINT received\n");
  sigaction (SIGINT, &saa, NULL);
}

int main(void) {
  sa.sa_handler = handler;

  sigaction (SIGINT, &sa, &saa);

  while(1) {}

  return 0;
}
