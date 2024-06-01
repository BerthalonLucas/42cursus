/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_uitls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:03:56 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/01 05:10:27 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void path_verif(t_pipex* pipex)
{
	char *tmp;

	if (find_dot_slash(pipex->cmd1[0]) == 1)
		pipex->cmd_path1 = strdup(pipex->cmd1[0]);
	else
	{
		path_maker(pipex->env, pipex);
		join_command_to_path(pipex, pipex->cmd1[0]);
		tmp = search_executable(pipex);
		if (tmp)
			pipex->cmd_path1 = strdup(tmp);
		else
			pipex->cmd_path1 = NULL;
	}
	if (find_dot_slash(pipex->cmd2[0]) == 1)
		pipex->cmd_path2 = strdup(pipex->cmd2[0]);
	else
	{
		path_maker(pipex->env, pipex);
		join_command_to_path(pipex, pipex->cmd2[0]);
		tmp = search_executable(pipex);
		if (tmp)
			pipex->cmd_path2 = strdup(tmp);
		else
			pipex->cmd_path2 = NULL;
	}
}

void	path_maker(char **env, t_pipex *pipex)
{
	int		i;
	char	*tmp_path;

	i = 0;
	tmp_path = NULL;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			tmp_path = strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	if (pipex->path)
		free_double_ptr(pipex->path, count_tab(pipex->path));
	pipex->path = ft_split(tmp_path, ':');
	free(tmp_path);
}

void	join_command_to_path(t_pipex *pipex, char *cmd)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 0;
	if (cmd[y] == '.' && cmd[y + 1] == '/')
		return ;
	if (pipex->path == NULL || pipex->path[0] == NULL)
		return ;
	while (pipex->path[i])
	{
		tmp = pipex->path[i];
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		free_ptr(tmp);
		tmp = pipex->path[i];
		pipex->path[i] = ft_strjoin(pipex->path[i], cmd);
		free_ptr(tmp);
		i++;
	}
}

char	*search_executable(t_pipex *pipex)
{
	char	*full_path;
	int		i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		full_path = pipex->path[i];
		if (access(full_path, X_OK) == 0)
			return (full_path);
		i++;
	}
	return (NULL);
}
