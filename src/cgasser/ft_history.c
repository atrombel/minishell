
#include "cgasser.h"

void	ft_history(char *user_input)
{
	if (*user_input != '\0')
		add_history(user_input);
}
