#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

main()
{
  int fd, status;

   fd = open("/dev/ttyS0", O_RDONLY);
   if (ioctl(fd, TIOCMGET, &status) == -1)
      printf("TIOCMGET failed: %s\n",
             strerror(errno));
   else {
      if (status & TIOCM_DTR)
         puts("TIOCM_DTR is not set");
      else
         puts("TIOCM_DTR is set");
   }
   close(fd);
}

/*
Ce programme ouvre un terminal (port série ) , puis appelle ioctl
avec le fd du port série , la commande TIOCMGET
et un pointeur vers un nombre entier dans lequel le résultat est renvoyé.


Le résultat de ioctl est ensuite vérifié pour voir si une erreur a été faite
dans le traitement de la demande. Si il n'y a pas de problèmes , nous vérifions la
valeurs renvoyées par eux anding avec TIOCM_DTR . Cette étape donne vrai
ou faux , non nul ou zéro , respectivement .*/