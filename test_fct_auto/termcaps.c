#include	<termios.h>
#include	<unistd.h>
#include 	<term.h>

int main(int ac, char **av, char **env)
{
	char *name_term;
	struct termios term;

	if (name_term = getenv("TERM") == NULL)
		return (- 1);
	if (tgetent(NULL, name_term) == ERR)
		return (- 1);
	if (tcgetattr(0, term) == -1)
		return (- 1);
	//on as remplis la structur termios term avec les infos du terminale
	// dont on aura besoin plus tard pour changer le comportement du terminal//
	term.c_lflag &= ~(ICANON); //mode canonique
	term.c_lflag &= ~(ECHO); // les touche tapés ne son plus afichées
	term.c_cc[VMIN] = 1;
	term.c_cc[TIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1) //applique les changements
		return(-1);
	//remets le term par default

	if (tcgetattr(0, &term) == -1)
   		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
   		return (-1);

}
