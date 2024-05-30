/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 07:41:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 07:44:14 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_files(t_pipex *pipex)
{
	pipex->infile = open(pipex->file1, O_RDONLY);
	if (pipex->infile == -1)
	{
		ft_fprintf(2, "failed to open infile\n");
		exit(1);
	}
	pipex->outfile = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		ft_fprintf(2, "failed to open outfile\n");
		exit(1);
	}
}
