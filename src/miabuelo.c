#include <stdio.h>
#include <unistd.h>

int main(void) {
  int pid, miAbuelo, miPadre, tubo[2];

  pipe(tubo);
  pid = fork();
  if (pid==0) {
      read (tubo[0], &miAbuelo, sizeof(miAbuelo));
      printf("[H] MiPadre = %5d Yo = %5d MiAbuelo = %5d\n", getppid(), getpid(), miAbuelo);

  } else {
      miPadre = getppid();
      write (tubo[1], &miPadre, sizeof(miPadre));
      printf("[P] MiPadre = %5d Yo = %5d MiHijo   = %5d\n", miPadre, getpid(), pid);
  }

  return 0;
}
