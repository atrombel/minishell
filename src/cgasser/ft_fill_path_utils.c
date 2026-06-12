/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:16:50 by cgasser           #+#    #+#             */
/*   Updated: 2026/06/12 14:17:55 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

char	*ft_make_path_name(char *cmd, char *path)
{
	char	*tmp;
	char	*res;

	tmp = NULL;
	res = NULL;
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(path, tmp);
	if (!res)
		return (free(tmp), NULL);
	free(tmp);
	return (res);
}
