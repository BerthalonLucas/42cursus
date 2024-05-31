/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:24:49 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 05:10:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_pipex(t_pipex *pipex, char **av, char **envp)
{
	pipex->file1 = av[1];
	pipex->file2 = av[4];
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->cmd2 = ft_split(av[3], ' ');
	pipex->env = envp;
	pipex->infile = 0;
	pipex->outfile = 0;
	pipex->cmd_path1 = NULL;
	pipex->cmd_path2 = NULL;
	pipex->path = NULL;
}


