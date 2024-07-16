/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 03:03:56 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/03 06:17:07 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	find_slash_access(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (((str[i] == '.' && str[i + 1] == '/') || (str[i] == '/'))
			|| access(str, F_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	path_create(t_pipex *pipex)
{
	char	*tmp_path;
	char	*joined_path;

	tmp_path = ft_strdup("/usr/local/sbin:/usr/local/bin:/usr/sbin");
	if (!tmp_path)
		return ;
	joined_path = ft_strjoin(tmp_path, ":/usr/bin:/sbin:/bin:/usr");
	free(tmp_path);
	if (!joined_path)
		return ;
	tmp_path = joined_path;
	joined_path = ft_strjoin(tmp_path, "/games:/usr/local/games:/snap/bin");
	free(tmp_path);
	if (!joined_path)
		return ;
	if (pipex->path)
		free_double_ptr(pipex->path, count_tab(pipex->path));
	pipex->path = ft_split(joined_path, ':');
	free(joined_path);
	if (!pipex->path)
		return ;
}
