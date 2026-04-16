
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "./cgasser.h"
# include "./atrombel.h"

//macro for token type
# define CMD "cmd" //command

typedef struct s_token //token
{
	char	*tok; //token
	char	*type; //type
	char	*flags; //flags
	int	fd_in; //fd of the input file
	int	fd_out; //fd of the output file
	
}	t_token;

#endif
