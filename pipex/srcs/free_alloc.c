/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:52:51 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 05:40:54 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex.h"

void free_all(t_pipex *pipex)
{
	if (pipex->cmd1)
		free_double_ptr(pipex->cmd1, count_tab(pipex->cmd1));
	if (pipex->cmd2)
		free_double_ptr(pipex->cmd2, count_tab(pipex->cmd2));
	if (pipex->path)
		free_double_ptr(pipex->path, count_tab(pipex->path));
	if (pipex->cmd_path1)
		free_ptr(pipex->cmd_path1);
	if (pipex->cmd_path2)
		free_ptr(pipex->cmd_path2);
}
