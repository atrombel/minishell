
#include "cgasser.h"

int	ft_check_quotes(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (quote == 0 && ft_isquote(str[i]))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		i++;
	}
	if (quote != 0)
		return (1);
	return (0);
}
