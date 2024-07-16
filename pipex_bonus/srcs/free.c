/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:52:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 06:35:14 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd1)
	{
		free_double_ptr(pipex->cmd1, count_tab(pipex->cmd1));
		pipex->cmd1 = NULL;
	}
	if (pipex->cmd2)
	{
		free_double_ptr(pipex->cmd2, count_tab(pipex->cmd2));
		pipex->cmd2 = NULL;
	}
	if (pipex->path)
	{
		free_double_ptr(pipex->path, count_tab(pipex->path));
		pipex->path = NULL;
	}
	free_all2(pipex);
}

void	free_all2(t_pipex *pipex)
{
	if (pipex->cmd_path1)
	{
		free_ptr(pipex->cmd_path1);
		pipex->cmd_path1 = NULL;
	}
	if (pipex->cmd_path2)
	{
		free_ptr(pipex->cmd_path2);
		pipex->cmd_path2 = NULL;
	}
}

void	error_exit(const char *message, t_pipex *pipex)
{
	ft_printf("Pipex: %s\n", message);
	free_all(pipex);
	exit(EXIT_FAILURE);
}
