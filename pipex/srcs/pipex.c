/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:07:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/01 08:19:47 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		ft_fprintf(2, "Exemple: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	init_pipex(&pipex, av, envp);
	path_verif(&pipex);
	ft_fork(&pipex);
	print_strcut(&pipex);
	free_all(&pipex);
	return (0);
}

void print_strcut(t_pipex *pipex)
{
	ft_printf("path: %t\n\n", pipex->path);
	ft_printf("cmd1: %t\n\n", pipex->cmd1);
	ft_printf("cmd2: %t\n\n", pipex->cmd2);
	ft_printf("file1: %s\n", pipex->file1);
	ft_printf("file2: %s\n", pipex->file2);
	ft_printf("infile: %d\n", pipex->infile);
	ft_printf("outfile: %d\n", pipex->outfile);
	ft_printf("cmd_path1: %s\n", pipex->cmd_path1);
	ft_printf("cmd_path2: %s\n", pipex->cmd_path2);
}
