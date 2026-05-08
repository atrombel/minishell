#include "minishell.h"



int	key_validity_check(char *arg,  t_env *env)
{
	int		i;

	i = 0;
	if (ft_isalpha(arg[0]) == 0 || arg[0] == '_')// check du premier char
	{
		printf("-minishell: export: '%s': not a valid identifier\n", arg);
		return (-1);
	}
	while(arg[i] != '=' && arg[i])//check if key is valid
	{
		printf("arg[i] = %c\n", arg[i]);
		if (ft_isalpha(arg[0]) == 0 || arg[0] == '_' || ft_isdigit(arg[i]) == 1)
		{
			printf("-minishell: export: '%s': not a valid XD identifier\n", arg);
			return (-1);
		}
		i++;
	}
	printf("arg[i] = %c\n", arg[i]);
	if (arg[i] == '=') // since key is valid and there is a '=' so value exist or is at least "".
		export_key_value(arg, i, env);
	// else// key is valid  and doesnt have a value
	// 	export_key(arg, env);
	return (0);
}// ATTENTION SI JE TAPE EXPORT a= PUIS EXPORT, export doit me display a=""

// la commande seule $export affiche tout env dans lordre avec delcare -x au debut
// faire une copie et la trier
void	ft_export(t_cmd *content, t_env *env)
{
	int		i;

	i = 0;
	// if (!(content->args || content->args[0] || content->args[0][0]))
	// 	export_without_args();//TO DO
	while(content->args[i])
	{
		key_validity_check(content->args[i], env);
		i++;
	}
}
