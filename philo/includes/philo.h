/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:57:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/09 03:44:13 by lberthal         ###   ########.fr       */
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
}		t_gb;

typedef struct s_philo
{
	int id;
	int stop;
	int time_to_die;
	int time_to_sleep;
	int time_to_eat;
	int last_time_eat;
	long long time_start;
	int has_eat;
	int nb_eat;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	pthread_mutex_t *print;
}		t_philo;

typedef struct s_a
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
	long long time_start;
	t_philo	**philo;
	t_gb	*gb;
	pthread_mutex_t *forks;
	pthread_mutex_t *print;
	
}				t_a;

void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int valid_args(int ac, char **av);
int valid_start(int ac, char **av);
long atol(const char *str);
void *routine(void *arg);
void *add_to_gb(t_gb *gb, void *ptr);
void free_gb(t_gb *gb);
void *new_malloc(t_a *a, size_t size);
void free_all(t_a *a);
void init_mutex(t_a *a);
void	init_philosophers(t_a *a);
long ft_atol(const char *str);
void	init_struct(t_a *a, int ac, char **av);
void *routine(void *arg);
void phtread_create_phi(t_a *a);
long long gt(void);
long long ct(long long time);
void put_time(t_a *a);
int current_time(t_philo *philo);

void print_struct_a(t_a *a);
void print_struct_philo(t_a *a);
void print_struct_philo_alone(t_philo *philo);
void ft_usleep(long long time_in_ms);


#endif

