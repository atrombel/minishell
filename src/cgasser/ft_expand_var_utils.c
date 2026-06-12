/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:32:01 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 14:11:10 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

void	ft_init_exp(t_expand *exp)
{
	exp->i = 0;
	exp->j = 0;
	exp->quote = 0;
	exp->is_alloc = 0;
	exp->value = NULL;
}

void	ft_update_quote(t_expand *exp, char c)
{
	if (exp->quote == 0 && ft_isquote(c))
		exp->quote = c;
	else if (exp->quote == c)
		exp->quote = 0;
}

char	*ft_get_value(char *start, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env != NULL)
	{
		if (ft_strncmp(start + 1, env->key,
				ft_strlen_varname(start) - 1) == 0
			&& env->key[ft_strlen_varname(start) - 1] == '\0')
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

//return the len of the variable name with the $: eg $USER -> 5
int	ft_strlen_varname(char *start)
{
	int	i;

	i = 1;
	if (start[i] == '?')
		return (i + 1);
	while (ft_isalnum(start[i]) || start[i] == '_')
		i++;
	return (i);
}

void	ft_incr_indexes(t_expand *exp)
{
	exp->i++;
	exp->j++;
}
