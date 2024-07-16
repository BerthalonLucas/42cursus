/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 03:15:12 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 06:24:32 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_process_fd(t_pipex *pipex, int *fd)
{
	int	infile_fd;

	close(fd[0]);
	infile_fd = open(pipex->file1, O_RDONLY);
	if (infile_fd == -1 || pipex->cmd_path1 == NULL)
		return (1);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	return (0);
}

void	child_process(t_pipex *pipex, int *fd)
{
	int	error;

	error = child_process_fd(pipex, fd);
	if (!error)
		execve(pipex->cmd_path1, pipex->cmd1, pipex->env);
	if (access(pipex->file1, R_OK) == -1 || access(pipex->file1, F_OK) == -1)
		ft_fprintf(2, "Pipex: %s: %s\n", pipex->file1, strerror(errno));
	else
	{
		if (pipex->cmd_path1 && access(pipex->cmd1[0], X_OK) == -1
			&& access(pipex->cmd1[0], F_OK) == 0)
			ft_fprintf(2, "Pipex: [%s] Permission denied\n", pipex->cmd1[0]);
		else if (!pipex->cmd_path1 && access(pipex->cmd1[0], F_OK) == -1)
			ft_fprintf(2, "Pipex: [%s] command not found\n", pipex->cmd1[0]);
		else
			ft_fprintf(2, "Pipex: [%s]: %s\n", pipex->cmd1[0], strerror(errno));
	}
	free_all(pipex);
	exit(EXIT_FAILURE);
}

int	child2_process_fd(t_pipex *pipex, int *fd)
{
	int	outfile_fd;

	outfile_fd = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1 || pipex->cmd_path2 == NULL)
		return (1);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	return (0);
}

void	child2_process(t_pipex *pipex, int *fd)
{
	int	error;

	error = child2_process_fd(pipex, fd);
	if (!error)
		execve(pipex->cmd_path2, pipex->cmd2, pipex->env);
	ft_usleep(1000000);
	if (access(pipex->file2, F_OK) == 0)
	{
		if (access(pipex->file2, W_OK) == -1
			|| access(pipex->file2, R_OK) == -1)
		{
			ft_fprintf(2, "Pipex: %s: %s\n", pipex->file2, strerror(errno));
			free_all(pipex);
			exit(EXIT_FAILURE);
		}
		if (pipex->cmd_path2 && access(pipex->cmd2[0], X_OK) == -1
			&& access(pipex->cmd2[0], F_OK) == 0)
			ft_fprintf(2, "Pipex: [%s] Permission denied\n", pipex->cmd2[0]);
		else if (!pipex->cmd_path2 && access(pipex->cmd2[0], F_OK) == -1)
			ft_fprintf(2, "Pipex: [%s] command not found\n", pipex->cmd2[0]);
		else
			ft_fprintf(2, "Pipex: [%s]: %s\n", pipex->cmd2[0], strerror(errno));
	}
	free_all(pipex);
	exit(EXIT_FAILURE);
}

void	ft_usleep(int time)
{
	int	i;

	i = 0;
	while (i < time)
		i++;
}
