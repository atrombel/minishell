/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:30:56 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 14:11:09 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include "ft_printf.h"
#include <stdlib.h>

int	ft_strlen_expanded_var(char *str, t_data *data);
int	ft_update_indexes(t_expand *exp, char *str, t_data *data);
int	ft_strcpy_expanded_var(char *res, char *str, t_data *data);
int	ft_cpy_value(t_expand *exp, char *res, char *str, t_data *data);

//take a string as parameter and expand variables starting with $
//return a string allocated with ft_calloc, and free original str
char	*ft_expand_var(char *str, t_data *data)
{
	char	*res;
	int		len;

	res = NULL;
	len = 0;
	if (!str)
		return (NULL);
	len = ft_strlen_expanded_var(str, data);
	if (len < 0)
		return (free(str), NULL);
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (free(str), perror("ft_expand_var"), NULL);
	if (ft_strcpy_expanded_var(res, str, data))
		return (free(str), NULL);
	free(str);
	return (res);
}

int	ft_strlen_expanded_var(char *str, t_data *data)
{
	t_expand	exp;

	ft_init_exp(&exp);
	while (str[exp.i] != '\0')
	{
		ft_update_quote(&exp, str[exp.i]);
		if (ft_update_indexes(&exp, str, data) != 0)
			return (-1);
	}
	return (exp.j);
}

int	ft_update_indexes(t_expand *exp, char *str, t_data *data)
{
	if (exp->quote != '\'' && str[exp->i] == '$' && str[exp->i + 1] != '\0')
	{
		if (ft_isalnum(str[exp->i + 1]) || str[exp->i + 1] == '_')
		{
			exp->value = ft_get_value(str + exp->i, data);
			if (exp->value)
				exp->j += ft_strlen(exp->value);
		}
		else if (str[exp->i + 1] == '?')
		{
			exp->value = ft_itoa(data->last_exit_status);
			if (!exp->value)
				return (perror("ft_strlen_expanded_var"), 1);
			exp->j += ft_strlen(exp->value);
			free (exp->value);
			exp->value = NULL;
		}
		exp->i += ft_strlen_varname(str + exp->i);
	}
	else
		ft_incr_indexes(exp);
	return (0);
}

int	ft_strcpy_expanded_var(char *res, char *str, t_data *data)
{
	t_expand	exp;

	ft_init_exp(&exp);
	while (str[exp.i] != '\0')
	{
		ft_update_quote(&exp, str[exp.i]);
		if (exp.quote != '\'' && str[exp.i] == '$' && str[exp.i + 1] != '\0')
		{
			if (ft_cpy_value(&exp, res, str, data) != 0)
				return (1);
		}
		else
		{
			res[exp.j] = str[exp.i];
			ft_incr_indexes(&exp);
		}
	}
	res[exp.j] = '\0';
	return (0);
}

int	ft_cpy_value(t_expand *exp, char *res, char *str, t_data *data)
{
	if (ft_isalnum(str[exp->i + 1]) || str[exp->i + 1] == '_')
	{
		exp->value = ft_get_value(str + exp->i, data);
		if (exp->value)
		{
			ft_strlcpy(res + exp->j, exp->value,
				ft_strlen(exp->value) + 1);
			exp->j += ft_strlen(exp->value);
		}
	}
	else if (str[exp->i + 1] == '?')
	{
		exp->value = ft_itoa(data->last_exit_status);
		if (!exp->value)
			return (perror("ft_strlen_expanded_var"), 1);
		ft_strlcpy(res + exp->j, exp->value,
			ft_strlen(exp->value) + 1);
		exp->j += ft_strlen(exp->value);
		free(exp->value);
		exp->value = NULL;
	}
	exp->i += ft_strlen_varname(str + exp->i);
	return (0);
}
