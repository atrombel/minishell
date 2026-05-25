#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

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
	rl_clear_history();
	exit(nbr);
}
