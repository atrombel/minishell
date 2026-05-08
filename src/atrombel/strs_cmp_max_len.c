#include "minishell.h"
int	strlen_max(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (j > i)
		return (j);
	else
		return (i);
}
