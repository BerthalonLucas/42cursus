/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 05:07:10 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/31 06:15:10 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **envp)
{
	t_pipex	pipex;


	(void)av;
	if (ac != 5)
	{
		ft_fprintf(2, "Exemple: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	init_pipex(&pipex, av, envp);
	ft_fork(&pipex);
	free_all(&pipex);
	return (0);
}
