/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:03:56 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 06:04:57 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void path_ready_cmd1(t_pipex *pipex)
{
	char *tmp_path1;
	
	path_maker(pipex->env, pipex);
	join_command_to_path(pipex, pipex->cmd1[0]);
	tmp_path1 = search_executable(pipex);
	pipex->cmd_path1 = ft_strdup(tmp_path1);
}

void path_ready_cmd2(t_pipex *pipex)
{
	char *tmp_path2;

	path_maker(pipex->env, pipex);
	join_command_to_path(pipex, pipex->cmd2[0]);
	tmp_path2 = search_executable(pipex);
	pipex->cmd_path2 = ft_strdup(tmp_path2);
}

void path_maker(char **env, t_pipex *pipex)
{
	int i;
	char *tmp_path;

	i = 0;
	if (pipex->path)
	{
		free_double_ptr(pipex->path, count_tab(pipex->path));
		return ;
	}
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			tmp_path = strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	pipex->path = ft_split(tmp_path, ':');
	free(tmp_path);
}

void	join_command_to_path(t_pipex *pipex, char *cmd)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (cmd[y] == '.' && cmd[y + 1] == '/')
		return ;
	while (pipex->path[i])
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		pipex->path[i] = ft_strjoin(pipex->path[i], cmd);
		i++;
	}
}

char	*search_executable(t_pipex *pipex)
{
	char    *full_path;
	int     i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		full_path = pipex->path[i];
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free_ptr(full_path);
		full_path = NULL;
		i++;
	}
	return (NULL);
}
