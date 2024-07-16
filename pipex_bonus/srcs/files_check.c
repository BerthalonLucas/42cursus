/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 07:41:52 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/01 05:36:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_perms_and_path(t_pipex *pipex)
{
	if (access(pipex->file1, R_OK) == -1 || access(pipex->file1, F_OK) == -1)
		ft_printf("Pipex: %s: %s\n", pipex->file1, strerror(errno));
	if (access(pipex->file2, F_OK) == 0)
	{
		if (access(pipex->file2, W_OK) == -1
			|| access(pipex->file2, R_OK) == -1)
			ft_printf("Pipex: %s: %s\n", pipex->file2, strerror(errno));
	}
}
