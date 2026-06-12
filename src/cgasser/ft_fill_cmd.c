/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:33:02 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 09:50:05 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

#include "ft_printf.h"

int	ft_fill_arg(t_cmd *cmd, char *word);
int	ft_valid_cmd(t_cmd *cmd);

int	ft_fill_cmd(t_cmd *cmd, char **word, t_data *data)
{
	*word = ft_expand_var(*word, data);
	if (!(*word))
		return (1);
	if (*word[0] == '\0')
		return (0);
	*word = ft_rm_quotes(*word);
	if (!(*word))
		return (1);
	if (ft_fill_arg(cmd, *word) != 0)
		return (1);
	if (ft_valid_cmd(cmd) != 0)
		return (1);
	if (ft_fill_path(cmd, data->env) != 0)
		return (1);
	return (0);
}

int	ft_fill_arg(t_cmd *cmd, char *word)
{
	char	*arg;
	char	**args;

	arg = NULL;
	arg = ft_calloc(sizeof(char), ft_strlen(word) + 1);
	if (!arg)
		return (1);
	ft_strlcpy(arg, word, ft_strlen(word) + 1);
	args = ft_arrayadd_back(cmd->args, arg);
	if (!args)
		return (free(arg), 1);
	cmd->args = args;
	return (0);
}

int	ft_valid_cmd(t_cmd *cmd)
{
	if (ft_arraysize(cmd->args) > 1)
		return (0);
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		cmd->is_valid = 1;
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		cmd->is_valid = 1;
	return (0);
}
