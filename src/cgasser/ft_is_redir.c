/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:25:42 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/11 16:25:44 by cgasser          ###   ####lausanne.ch   */
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
		return (IN_DELIM);
	if (ft_strncmp(str, ">>", 3) == 0)
		return (OUT_APPN);
	return (0);
}
