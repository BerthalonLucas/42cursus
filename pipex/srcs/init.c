/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:24:49 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 06:37:03 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_pipex(t_pipex *pipex, char **av, char **envp)
{
	ft_bzero(pipex, sizeof(t_pipex));
	pipex->file1 = av[1];
	pipex->file2 = av[4];
	if (av[2] == NULL || av[3] == NULL || av[2][0] == '\0' || av[3][0] == '\0')
		error_exit("No command", pipex);
	else
	{
		pipex->cmd1 = ft_split(av[2], ' ');
		pipex->cmd2 = ft_split(av[3], ' ');
	}
	pipex->env = envp;
}
