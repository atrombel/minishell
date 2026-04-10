
#ifndef CGASSER_H
# define CGASSER_H

typdef	struct s_node
{
	stuct s_node	*next;
	void		*data;
}	t_node

void	ft_parse(int argc, char **argv);
t_node	*ft_make_lst(int argc, char **argv);

#endif
