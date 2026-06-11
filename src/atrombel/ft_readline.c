/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:00:58 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/05 16:00:58 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

char	*getcwd_secured_for_ftreadline(t_env *env)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		str = ft_get_value_env(env, "PWD");
		if (!str)
		{
			str = ft_strdup("minishell");
			if (!str)
			{
				perror("minishell: ");
				return (NULL);
			}
		}
	}
	return (str);
}

void	ft_handle_eof(t_env *env)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	ft_env_clean(env);
	rl_clear_history();
	exit(0);
}

char	*ft_readline_pipe(t_env *env)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		ft_handle_eof(env);
	trimmed = ft_strtrim(line, "\n");
	free(line);
	return (trimmed);
}

char	*ft_readline(t_env *env)
{
	char	*user_input;
	char	*dest;
	char	*str;

	if (!isatty(STDIN_FILENO))
		return (ft_readline_pipe(env));
	str = getcwd_secured_for_ftreadline(env);
	if (!str)
		return (NULL);
	dest = ft_strjoin("\001\033[1;32m\002", str);
	if (!dest)
		return (perror("minishell: "), NULL);
	free(str);
	str = ft_strjoin(dest, "\001\033[0m\002$ ");
	free(dest);
	if (!str)
		return (perror("minishell: "), NULL);
	user_input = readline(str);
	free (str);
	if (!user_input)
		ft_handle_eof(env);
	return (user_input);
}
