
#include "minishell.h"
#include "ft_printf.h"
#include <stdlib.h>

char	*ft_put_var(char *str, t_env *env, int i);
int	ft_var_name_len(char *str, int i);
char	*ft_cpy_value(char *str, t_env *env, int i, int var_name_len);
t_env	*ft_get_value(char *str, t_env *env, int i, int var_name_len);

//take a string as parameter and expand variables starting with $
//return a string allocated with ft_calloc, and free original str
char	*ft_expand_var(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '"')
			str = ft_put_var(str, env, i);
		else
			i++;
	}
	return (str);
}

//takes as argument the orignial string and the index of the '$'
//and return the full string with the $NAME replaced by the value
char	*ft_put_var(char *str, t_env *env, int i)
{
	char	*value;
	char	*res;
	char	*str2;
	int		var_name_len;
	int		size;

	var_name_len = ft_var_name_len(str, i);
	value = ft_cpy_value(str, env, i, var_name_len);
	str2 = str + i + var_name_len;
	size = i + ft_strlen(str2) + 1;
	if (value)
		size += ft_strlen(value);
	res = ft_calloc(sizeof(char), size);
	ft_strlcpy(res, str, i + 1);
	if (value)
		ft_strlcat(res, value, size);
	ft_strlcat(res, str2, size);
	free(str);
	return (res);
}

//count the len of the variable name $NAME
int	ft_var_name_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] != '"' && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

//copy the value from the node returned by ft_get_value
char	*ft_cpy_value(char *str, t_env *env, int i, int var_name_len)
{
	t_env	temp;
	char	*value;
	int		value_len;
	int		j;

	temp = NULL;
	temp = ft_get_value(str, env, i, var_name_len);
	if (!temp)
		return (NULL);
	value_len = ft_strlen(temp->value);
	value = ft_calloc(sizeof(char), value_len + 1);
	ft_strlcpy(value, temp->value, value_len + 1);
	return (value);
}

//check if a variable of var $NAME exist in env
//return a pointer to the node, NULL otherwise
t_env	*ft_get_value(char *str, t_env *env, int i, int var_name_len)
{
	t_env	temp;
	char	*var_name;

	temp = NULL;
	temp = env;
	var_name = str + i + 1;
	while (temp != NULL)
	{
		if (ft_strncmp(var_name, temp->key, var_name_len - 1) == 0)
			break;
		temp = temp->next;
	}
	return (temp);
}
