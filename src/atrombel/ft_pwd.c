#include "minishell.h"
#include "atrombel.h"

//pwd - print name of current/working directory -> error code to handle !
void	ft_pwd(t_data *data, t_env *env)
{
	char	*pwd;

	pwd = ft_get_value_env(env, "PWD");
	if (printf("%s\n", pwd) < 0)
		data->last_exit_status = 1;
	free(pwd);
}
