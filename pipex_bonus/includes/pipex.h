/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:10:28 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 06:59:53 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	char	*file1;
	char	*file2;
	char	**cmd1;
	char	**cmd2;
	char	**env;
	char	**path;
	char	*cmd_path1;
	char	*cmd_path2;
	int		infile;
	int		outfile;
}	t_pipex;

void	ft_fork(t_pipex *pipex);
void	init_pipex(t_pipex *pipex, char **av, char **envp);
void	free_all(t_pipex *pipex);
void	free_all2(t_pipex *pipex);
void	join_command_to_path(t_pipex *pipex, char *cmd);
void	path_maker(char **env, t_pipex *pipex);
void	path_create(t_pipex *pipex);
void	program_path(t_pipex *pipex);
int		child_process_fd(t_pipex *pipex, int *fd);
void	child_process(t_pipex *pipex, int *fd);
int		child2_process_fd(t_pipex *pipex, int *fd);
void	child2_process(t_pipex *pipex, int *fd);
void	ft_childs(t_pipex *pipex, pid_t pid_main, int fd[2]);
void	error_exit(const char *message, t_pipex *pipex);
char	*search_executable(t_pipex *pipex);
int		find_slash_access(char *str);
void	path_verif(t_pipex *pipex);
void	ft_usleep(int time);
void	path_verif_2(t_pipex *pipex);

#endif
