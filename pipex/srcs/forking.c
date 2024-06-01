/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:28:23 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/01 07:08:31 by lberthal         ###   ########.fr       */
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

	if (pid_main != 0)
	{
		child2 = fork();
		if (child2 == -1)
			error_exit("fork", pipex);
		if (child2 == 0)
			child2_process(pipex, fd);
		else
			wait_for_childs();
	}
	else
		child_process(pipex, fd);
}

void	wait_for_childs(void)
{
	int	status;

	wait(&status);
	// ft_printf("status: %d\n", status);
	// if (WIFEXITED(status))
	// {
	// 	ft_printf("child process exited with status %d\n", WEXITSTATUS(status));
	// }
	// else
	// 	ft_printf("child process exited abnormally\n");
}
