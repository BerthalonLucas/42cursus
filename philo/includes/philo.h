/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:57:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/08 07:02:40 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h> 
#include <string.h>
#include <ctype.h>

typedef struct s_gb
{
	void	*ptr;
	struct s_gb	*next;
}		gb_t;

typedef struct s_philo
{
	int id;
	int stop;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
}		philo_t;

typedef struct s_a
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
	int time_start;
	philo_t	**philo;
	gb_t	*gb;
}				a_t;

void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int valid_args(int ac, char **av);
int valid_start(int ac, char **av);
long atol(const char *str);
void *routine(void *arg);


#endif // PHILO_H
