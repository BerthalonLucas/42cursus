/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:07:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 07:41:23 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		f_printf(2, "Exemple: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	init_pipex(&pipex, av);
	open_files(&pipex);
	ft_fork(&pipex);
}
