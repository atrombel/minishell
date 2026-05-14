#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

// first check like the true exit that stop directly when not number
// int	ft_check_if_not_nbr(t_cmd *content) // A CONFIRMER SI INUTILE, SOLUTIOON ATOI BETTER
// {
// 	int	x;
// 	int	y;
// 	int	tmp;

// 	x = 0;
// 	while (content->args[x])
// 	{
// 		y = 0;
// 		while (content->args[x][y])
// 		{
// 			tmp = content->args[x][y];
// 			if (!((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+'))
// 			{
// 				printf("-minishell: exit: %s: numeric argument required\n", content->args[0]); // remplacer par un printf dans fd 2
// 				return (-1);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (0);
// }

//	exit - cause normal process termination
// a voir si rajouter data et code erreur
void	ft_exit(t_cmd *content, t_env *env, t_list *head)
{
	int	nbr;
	t_list	*args;

	args = content->args;
	nbr = EXIT_SUCCESS;
	if (args)
	{
		// if (ft_check_if_not_nbr(content) == -1)
		// {
		// 	ft_lstclear(&head, ft_free_cmd);
		// 	ft_env_clean(env);
		// 	exit(2);//2 code erreur pour builtin mal utilise ou syntaxe // code 1 est généralement utilisé pour les erreurs générales
		// }
		if (((char *)args->content)[1])
		{
			printf("-minishell: exit: too many arguments\n"); // remplacer par un printf fans fd 2, securiser printf ?
			return ;
		}
		if (((char *)args->content) &&((char *)args->content)[0])
		{
			nbr = ft_atoi(((char *)args->content));
			if (nbr == 0 &&((char *)args->content)[0] != '0')
			{
				printf("-minishell: exit: %s: numeric argument required\n",((char *)args->content)); // remplacer par un printf dans fd 2
				//return ; mon wsl exit quand meme a voir ubuntu ecole
				nbr = 2;
			}
		}
	}
	ft_env_clean(env);
	ft_clear_cmds(&head);// A DEMANDER CYRILLE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	exit(nbr);
}
