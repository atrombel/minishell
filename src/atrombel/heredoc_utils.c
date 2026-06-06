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

void	sigint_heredoc(t_redir *redir, t_data *data, char	*input)
{
	g_sig = 0;
	data->last_exit_status = 130;
	free(input);
	close(redir->hd_tmp_fd);
	unlink(redir->hd_filename);
	ft_signals();
}
void	if_heredoc_eof_detected(t_redir *redir, char	*input)
{
	free(input);
	close(redir->hd_tmp_fd);
	redir->hd_tmp_fd = open(redir->hd_filename, O_RDONLY);
	if (redir->hd_tmp_fd < 0)
		perror("minishell: heredoc");
	unlink(redir->hd_filename);
}

void	heredoc_input_trim(	char	*input)
{
	int		i;

	i = ft_strlen(input) - 1;
	if (input[i] == '\n')
		input[i] = '\0';
}
