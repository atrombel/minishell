/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:47:45 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/08 09:47:45 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"

int	secure_close(int *fd)
{
	if (fd && *fd >= 0)
	{
		if (close(*fd) == -1)
		{
			error_print("close error");
			*fd = -1;
			return (1);
		}
		*fd = -1;
	}
	return (0);
}
