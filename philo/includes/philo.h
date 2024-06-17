/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:57:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/06/17 21:42:19 by lberthal         ###   ########.fr       */
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

struct s_philo;
struct s_a;

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
	int has_eat;
	int nb_eat;
	size_t time_start;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	struct s_a *a;
}		t_philo;

typedef struct s_a
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		stop;
	int		nb_eat;
	size_t time_start;
	t_philo	**philo;
	t_gb	*gb;
	pthread_t *monitor;
	pthread_mutex_t *print;
	pthread_mutex_t *forks;
	pthread_mutex_t *stop_m;
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
size_t gt(void);
size_t current_time(size_t time);
void put_time(t_a *a);

void ft_usleep(size_t time_in_ms);
void *monitoring(void *arg);
int print_state(t_philo *philo, int state);
int who_pick_the_fork(t_philo *philo);


#endif

