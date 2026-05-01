
#include "minishell.h"
#include "ft_printf.h"
#include <stdlib.h>

char	*ft_put_var(char *str, char **envp, int i);
int	ft_var_name_len(char *str, int i);
char	*ft_get_value(char *str, char **envp, int i, int var_name_len);
int	ft_check_var(char *str, char **envp, int i, int var_name_len);

//take a string as parameter and expand variables starting with $
//return a string allocated with ft_calloc, and free original str
char	*ft_expand_var(char *str, char **envp)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '"')
			str = ft_put_var(str, envp, i);
		else
			i++;
	}
	return (str);
}

//takes as argument the orignial string and the index of the '$'
//and return the full string with the $NAME replaced by the value
char	*ft_put_var(char *str, char **envp, int i)
{
	char	*value;
	char	*res;
	char	*str2;
	int		var_name_len;
	int		size;

	var_name_len = ft_var_name_len(str, i);
	value = ft_get_value(str, envp, i, var_name_len);
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

//get the value of the variable $NAME
char	*ft_get_value(char *str, char **envp, int i, int var_name_len)
{
	char	*value;
	int		value_len;
	int		j;

	j = ft_check_var(str, envp, i, var_name_len);
	if (j == -1)
		return (NULL);
	value_len = ft_strlen(envp[j] + var_name_len);
	value = ft_calloc(sizeof(char), value_len + 1);
	ft_strlcpy(value, envp[j] + var_name_len, value_len + 1);
	return (value);
}

//check if a variable of var $NAME exist in envp
//return its index in envp, -1 otherwise
int	ft_check_var(char *str, char **envp, int i, int var_name_len)
{
	int		j;
	char	*var_name;

	j = 0;
	var_name = str + i + 1;
	while (envp[j] != NULL)
	{
		if (ft_strncmp(var_name, envp[j], var_name_len - 1) == 0)
		{
			if (*(envp[j] + var_name_len - 1) == '=')
				return (j);
		}
		j++;
	}
	return (-1);
}
