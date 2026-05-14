
#include "cgasser.h"

int	ft_is_redir(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (IN);
	if (ft_strncmp(str, ">", 2) == 0)
		return (OUT);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (IN_DELIM);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (OUT_APPN);
	return (0);
}
