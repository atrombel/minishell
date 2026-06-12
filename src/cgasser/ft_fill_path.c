/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 08:38:52 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 14:17:56 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include "ft_printf.h"

int		ft_fill_path_checks(t_cmd *cmd);
char	*ft_cpy_end_path(char *path);
char	**ft_get_paths(t_env *env);
int		ft_select_and_cpy_path(t_cmd *cmd, t_env *env);

int	ft_fill_path(t_cmd *cmd, t_env *env)
{
	if (ft_fill_path_checks(cmd) == 0)
		return (0);
	if (access(cmd->args[0], X_OK) == 0)
	{
		cmd->path = cmd->args[0];
		cmd->args[0] = ft_cpy_end_path(cmd->path);
		if (!cmd->args[0])
			return (1);
	}
	else
	{
		if (ft_select_and_cpy_path(cmd, env) != 0)
			return (1);
	}
	if (cmd->path)
		cmd->is_valid = 1;
	return (0);
}

int	ft_fill_path_checks(t_cmd *cmd)
{
	if (ft_arraysize(cmd->args) > 1)
		return (0);
	if (cmd->is_valid)
		return (0);
	if (ft_strlen(cmd->args[0]) == 0)
		return (0);
	if (cmd->args[0][ft_strlen(cmd->args[0]) - 1] == '/')
		return (0);
	return (1);
}

char	*ft_cpy_end_path(char *path)
{
	int		i;
	int		size;
	char	*res;

	i = ft_strlen(path);
	res = NULL;
	while (path[i] != '/' && i != 0)
		i--;
	if (i == 0)
		return (NULL);
	size = ft_strlen(path) - i;
	res = ft_calloc(sizeof(char), size);
	if (!res)
		return (NULL);
	ft_strlcpy(res, path + i + 1, size);
	return (res);
}

char	**ft_get_paths(t_env *env)
{
	char	*paths;
	char	**split_paths;

	paths = NULL;
	split_paths = NULL;
	paths = ft_get_value_env(env, "PATH");
	if (!paths)
		return (NULL);
	split_paths = ft_split(paths, ':');
	if (!split_paths)
		return (free(paths), NULL);
	free(paths);
	return (split_paths);
}

int	ft_select_and_cpy_path(t_cmd *cmd, t_env *env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	paths = ft_get_paths(env);
	if (!paths)
		return (1);
	while (paths[i] != NULL)
	{
		cmd->path = ft_make_path_name(cmd->args[0], paths[i]);
		if (!cmd->path)
			return (ft_free_array(paths), 1);
		if (access(cmd->path, X_OK) == 0)
			return (ft_free_array(paths), 0);
		free(cmd->path);
		i++;
	}
	ft_free_array(paths);
	cmd->path = NULL;
	return (0);
}
