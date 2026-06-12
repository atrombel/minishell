/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:25:42 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 11:18:50 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_is_redir(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (IN);
	if (ft_strncmp(str, ">", 2) == 0)
		return (OUT);
	if (ft_strncmp(str, "<<", 3) == 0)
		return (HEREDOC);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (APPEND);
	return (0);
}
