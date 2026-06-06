/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:56:10 by cgasser           #+#    #+#             */
/*   Updated: 2025/11/25 11:21:53 by cgasser        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_fill_res(char *holder);
char		*ft_update_holder(char *holder);
int			init_holder(char **holder);
int			ft_read_and_join(int fd, char **holder, char *buffer);

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*res;
	int			status;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!init_holder(&holder))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_gnl(&holder), NULL);
	status = ft_read_and_join(fd, &holder, buffer);
	ft_free_gnl(&buffer);
	if (status < 0)
		return (NULL);
	res = ft_fill_res(holder);
	if (!res)
		return (ft_free_gnl(&holder), NULL);
	holder = ft_update_holder(holder);
	return (res);
}

char	*ft_fill_res(char *holder)
{
	char	*newline;
	char	*res;

	if (!holder)
		return (NULL);
	newline = ft_strchr(holder, '\n');
	if (newline == NULL)
	{
		if (ft_strlen(holder) == 0)
			return (NULL);
		res = malloc(sizeof(char) * (ft_strlen(holder) + 1));
		if (!res)
			return (NULL);
		ft_memcpy(res, holder, ft_strlen(holder) + 1);
	}
	else
	{
		res = malloc(sizeof(char) * (newline - holder + 2));
		if (!res)
			return (NULL);
		ft_memcpy(res, holder, newline - holder + 1);
		res[newline - holder + 1] = '\0';
	}
	return (res);
}

char	*ft_update_holder(char *holder)
{
	char	*newline;
	int		len;
	char	*tmp;

	if (!holder)
		return (NULL);
	newline = ft_strchr(holder, '\n');
	if (newline == NULL || newline[1] == '\0')
	{
		tmp = malloc(sizeof(char));
		if (!tmp)
			return (ft_free_gnl(&holder), NULL);
		tmp[0] = '\0';
	}
	else
	{
		len = ft_strlen(newline + 1) + 1;
		tmp = malloc(sizeof(char) * len);
		if (!tmp)
			return (ft_free_gnl(&holder), NULL);
		ft_memcpy(tmp, newline + 1, len);
	}
	ft_free_gnl(&holder);
	return (tmp);
}

int	init_holder(char **holder)
{
	if (!*holder)
	{
		*holder = malloc(1);
		if (!*holder)
			return (0);
		(*holder)[0] = '\0';
	}
	return (1);
}

int	ft_read_and_join(int fd, char **holder, char *buffer)
{
	int		buff;
	char	*tmp;

	buff = BUFFER_SIZE;
	if (!holder || !*holder || !buffer)
		return (-1);
	while (*holder && !ft_strchr(*holder, '\n'))
	{
		buff = read(fd, buffer, BUFFER_SIZE);
		if (buff <= 0)
		{
			if (buff == 0 && *holder && ft_strlen(*holder) != 0)
				break ;
			return (ft_free_gnl(holder), -1);
		}
		buffer[buff] = '\0';
		tmp = *holder;
		*holder = ft_strjoin(tmp, buffer);
		ft_free_gnl(&tmp);
		if (!*holder)
			return (-1);
	}
	return (1);
}
