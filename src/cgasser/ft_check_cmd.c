

#include "minishell.h"
#include "cgasser.h"
#include "ft_printf.h"

//check if a string passed as argument is a valid command or not
//fill the type

int	ft_check_cmd(t_token *token)
{
	if (ft_strncmp(token->word, "echo", 4) == 0)
		token->type = CMD;
	else
	{
		ft_printr("Error\nUnvalid command: %s\n", token->word);
		return (1);
	}
	return (0);
}
