/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:58:06 by anchikri          #+#    #+#             */
/*   Updated: 2023/11/01 04:58:06 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &str[i]);
	return (0);
}

void	ft_update_line_and_buffer(char **line, char *buffer)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	len = ft_strlen(*line + i + 1);
	ft_memmove(buffer, *line + i + 1, len);
	buffer[len] = '\0';
	if ((*line)[i] == '\n')
	{
		tmp = ft_substr(*line, 0, i + 1);
		if (!tmp)
			return ;
		free(*line);
		*line = tmp;
	}
}

void	ft_read(int fd, char **line, char *buffer, int *br)
{
	*br = 1;
	while (!ft_strchr(buffer, '\n') && *br != 0)
	{
		*br = read(fd, buffer, BUFFER_SIZE);
		if (*br == -1)
		{
			buffer[0] = '\0';
			free(*line);
			*line = NULL;
			return ;
		}
		buffer[*br] = '\0';
		*line = ft_strjoin(*line, buffer);
		if (!*line)
			return ;
	}
}

int	ft_check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				br;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin(NULL, buffer[fd]);
	ft_read(fd, &line, buffer[fd], &br);
	if (!ft_check(br, &line))
		return (NULL);
	if (br <= 0)
		return (line);
	ft_update_line_and_buffer(&line, buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	char *name = "to_read.txt";
// 	char *other = "other.txt";
// 	char *line1;
// 	char *line2;
// 	int fd = open(name, O_RDONLY);
// 	int fd2 = open(other, O_RDONLY);
// 	printf("output needed \n---------------------\naaaaaaaaaa\n\nlundi\n\nbbbbbbbbbb\n\nmardi\n\nNULL\n\nmercredi\n\naaaaaaaaaa\n\n");
// 	printf("jeudi\n\nbbbbbbbbbb\n\nccccccccc\n\nvendredi\n\nNULL\n\ndddddddddd\n\nNULL\n\n---------------------\nMY OUTPUT\n----------------------------\n");
// 	/* 1 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 2 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line2);
// 	free(line2);
// 	/* 3 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 4 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line2);
// 	free(line2);
// 	/* 5 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	close(fd);
// 	/* 6 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line2);
// 	free(line2);
// 	fd = open(name, O_RDONLY);
// 	/* 7 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 8 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line2);
// 	free(line2);
// 	/* 9 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 10 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 11 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line2);
// 	free(line2);
// 	/* 12 */ line2 = get_next_line(fd2);
// 	if (line2 == NULL)
// 		printf("NULL\n");
// 	free(line2);
// 	/* 13 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// 	/* 14 */ line1 = get_next_line(fd);
// 	if (line1 == NULL)
// 		printf("NULL\n");
// 	else
// 		printf("%s\n", line1);
// 	free(line1);
// }