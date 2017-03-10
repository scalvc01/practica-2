#include <stdio.h>
#include <signal.h>

int main(void) {
  sigaction (SIGINT, SIG_IGN, NULL);

  while(1) {}

  return 0;
}
