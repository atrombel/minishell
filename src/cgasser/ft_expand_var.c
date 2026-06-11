
#include "cgasser.h"
#include "ft_printf.h"
#include <stdlib.h>

int	ft_strlen_expanded_var(char *str, t_data *data);
char	*ft_get_value(char *start, t_data *data);
int	ft_strlen_varname(char *start);
int	ft_strcpy_expanded_var(char *res, char *str, t_data *data);

//take a string as parameter and expand variables starting with $
//return a string allocated with ft_calloc, and free original str
char	*ft_expand_var(char *str, t_data *data)
{
	char	*res;
	int		expanded_len;

	res = NULL;
	expanded_len = 0;
	if (!str)
		return (NULL);
	expanded_len = ft_strlen_expanded_var(str, data);
	if (expanded_len < 0)
		return (free(str), NULL);
	res = ft_calloc(sizeof(char), expanded_len + 1);
	if (!res)
		return (free(str), perror("ft_expand_var"), NULL);
	if (ft_strcpy_expanded_var(res, str, data))
		return (free(str), NULL);
	free(str);
	return (res);
}

int	ft_strlen_expanded_var(char *str, t_data *data)
{
	int		i;
	int		quote;
	int		len;
	int		is_allocated;
	char	*value;

	i = 0;
	quote = 0;
	len = 0;
	is_allocated = 0;
	value = NULL;
	while (str[i] != '\0')
	{
		if (quote == 0 && ft_isquote(str[i]))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (quote != '\'' && str[i] == '$' && (ft_isalnum(str[i + 1]) \
			|| str[i + 1] == '_' || str[i + 1] == '?'))
		{
			value = ft_get_value(str + i, data);
			if (!value && str[i + 1] == '?')
			{
				value = ft_itoa(data->last_exit_status);
				if (!value)
					return (perror("ft_strlen_expanded_var"), -1);
				is_allocated = 1;
			}
			if (value)
			{
				len += ft_strlen(value);
				if (is_allocated)
				{
					free (value);
					is_allocated = 0;
				}
			}
			i += ft_strlen_varname(str + i);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*ft_get_value(char *start, t_data *data)
{
	t_env	*env;

	env = data->env;
	while (env != NULL)
	{
		if (ft_strncmp(start + 1, env->key, \
			ft_strlen_varname(start) - 1) == 0 && \
				env->key[ft_strlen_varname(start) - 1] == '\0')
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

//ft_strlen_varname: return the len of the variable name with the $: eg $USER -> 5

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

int	ft_strcpy_expanded_var(char *res, char *str, t_data *data)
{
	int		i;
	int		j;
	int		quote;
	int		is_allocated;
	char	*value;

	i = 0;
	j = 0;
	quote = 0;
	is_allocated = 0;
	value = NULL;
	while (str[i] != '\0')
	{
		if (quote == 0 && ft_isquote(str[i]))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (quote != '\'' && str[i] == '$' && (ft_isalnum(str[i + 1]) \
			|| str[i + 1] == '_' || str[i + 1] == '?'))
		{
			value = ft_get_value(str + i, data);
			if (!value && str[i + 1] == '?')
			{
				value = ft_itoa(data->last_exit_status); //penser à free
				if (!value)
					return (perror("ft_strlen_expanded_var"), 1);
				is_allocated = 1;
			}
			if (value)
			{
				ft_strlcpy(res + j, value, ft_strlen(value) + 1);
				j += ft_strlen(value);
				if (is_allocated)
				{
					free(value);
					is_allocated = 0;
				}

			}
			i += ft_strlen_varname(str + i);
		}
		else
		{
			res[j] = str[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (0);
}
