
#include "minishell.h"
#include "atrombel.h"


// REMPLACER TOUT LES PRINTFS DERREUR PAR CA SI POSSIBLE
// str doit etre la commande le nom de fricheir etc un char * du probleme
void	error_print(char *str)
{
	if (!str)
		return;
	write(2, "minishell: ", 11);
	ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 1);
}
