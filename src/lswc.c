#include <stdio.h>
#include <unistd.h>

int main(void) {
  int tube[2];
  pipe(tube);
  if (fork() != 0) {
    dup2(tube[1], 1); /* Salida estandar => tubo[1] */
    close(tube[0]); /* Cerramos extremo lectura */
    execl("/bin/ls", "ls", "-l", NULL); /* El Padre ejecuta el comando ls */
  } else {
    dup2 (tube[0], 0); /* Salida estandar => tubo[0] */ 
    close(tube[1]); /* Cerramos extremo escritura */
    execl("/usr/bin/wc", "wc", NULL); /* El Hijo  ejecuta el comando wc */
  }

  return 0;
}
