/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:28:23 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/02 05:41:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_fork(t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		free_all(pipex);
		error_exit("pipe", pipex);
	}
	pid = fork();
	if (pid == -1)
	{
		free_all(pipex);
		error_exit("fork", pipex);
	}
	ft_childs(pipex, pid, fd);
}

void	ft_childs(t_pipex *pipex, pid_t pid_main, int *fd)
{
	pid_t	child2;
	int		status;

	if (pid_main != 0)
	{
		child2 = fork();
		if (child2 == -1)
			error_exit("fork", pipex);
		if (child2 == 0)
			child2_process(pipex, fd);
		else
			wait(&status);
	}
	else
		child_process(pipex, fd);
}
