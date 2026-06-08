/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:22:14 by atrombel          #+#    #+#             */
/*   Updated: 2026/06/06 16:22:14 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "atrombel.h"
#include "cgasser.h"

void	sigint_heredoc(t_redir *redir, t_data *data, char *input)
{
	g_sig = 0;
	data->last_exit_status = 130;
	free(input);
	secure_close(&redir->hd_tmp_fd);
	if (redir->hd_filename)
	{
		if (unlink(redir->hd_filename) == -1)
			perror("minishell: unlink");
	}
	ft_signals();
}

void	if_heredoc_eof_detected(t_redir *redir, char *input)
{
	free(input);
	secure_close(&redir->hd_tmp_fd);
	redir->hd_tmp_fd = open(redir->hd_filename, O_RDONLY);
	if (redir->hd_tmp_fd < 0)
		perror("minishell: heredoc");
	if (redir->hd_filename)
	{
		if (unlink(redir->hd_filename) == -1)
			perror("minishell: unlink");
	}
}

void	heredoc_input_trim(	char	*input)
{
	int		i;

	i = ft_strlen(input) - 1;
	if (input[i] == '\n')
		input[i] = '\0';
}

int	heredoc_loop(t_redir *redir, t_data *data)
{
	char	*input;
	int		len;

	len = ft_strlen(redir->arg);
	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (g_sig == SIGINT)
			return (sigint_heredoc(redir, data, input), -1);
		if (!input)
			return (hd_ctrl_d(data, redir), 0);
		heredoc_input_trim(input);
		if (ft_strncmp(input, redir->arg, len + 1) == 0)
			return (if_heredoc_eof_detected(redir, input), 0);
		if (redir->is_expanded == 1)
		{
			input = ft_expand_var(input, data);
			if (!input)
				return (-1);
		}
		ft_putstr_fd(input, redir->hd_tmp_fd);
		ft_putstr_fd("\n", redir->hd_tmp_fd);
		free(input);
	}
}
