/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:28:23 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 06:15:21 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    ft_fork(t_pipex *pipex)
{
	int     fd[2];
	pid_t   pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	ft_childs(pipex, pid, fd);
}

void	ft_childs(t_pipex *pipex, pid_t pid_main, int fd[2])
{
	pid_t	child2;
	
	if (pid_main != 0)
	{
		child2 = fork();
		if (child2 == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child2 == 0)
		{
			path_ready_cmd2(pipex);
			child2_process(pipex, fd);
		}
		else
			wait_for_childs();
	}
	else
	{
		path_ready_cmd1(pipex);
		child_process(pipex, fd);
	}
}
void	wait_for_childs(void)
{
	int status;
	int i;

	i = 0;
	while (i < 2)
	{
		wait(&status);
		if (WIFEXITED(status))
			ft_printf("child process exited with status %d\n", WEXITSTATUS(status));
		else
			ft_printf("child process exited abnormally\n");
		i++;
	}
}

void    child_process(t_pipex *pipex, int *fd)
{
	int     infile_fd;

	close(fd[0]);
	infile_fd = open(pipex->file1, O_RDONLY);
	if (infile_fd == -1)
	{
		ft_fprintf(2, "infile: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (!pipex->cmd_path1)
	{
		ft_fprintf(2, "Command not found: %s\n", pipex->cmd1[0]);
		exit(EXIT_FAILURE);
	}
	execve(pipex->cmd_path1, pipex->cmd1, pipex->env);
	perror("execve");
	free(pipex->cmd_path1);
	exit(EXIT_FAILURE);
}

void    child2_process(t_pipex *pipex, int *fd)
{
	int     outfile_fd;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	outfile_fd = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		ft_fprintf(2, "outfile: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	if (!pipex->cmd_path2)
	{
		ft_fprintf(2, "Command not found: %s\n", pipex->cmd2[0]);
		exit(EXIT_FAILURE);
	}
	execve(pipex->cmd_path2, pipex->cmd2, pipex->env);
	perror("execve");
	free(pipex->cmd_path2);
	exit(EXIT_FAILURE);
}
