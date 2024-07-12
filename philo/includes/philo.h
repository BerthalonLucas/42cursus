/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:57:54 by lberthal          #+#    #+#             */
/*   Updated: 2024/07/12 03:24:59 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ctype.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_gb
{
	void			*ptr;
	struct s_gb		*next;
}					t_gb;

typedef struct s_philo
{
	int				id;
	int				stop;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				last_time_eat;
	int				has_eat;
	int				nb_eat;
	size_t			time_start;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				has_left;
	int				has_right;
	struct s_a		*a;
}					t_philo;

typedef struct s_a
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				stop;
	int				nb_eat;
	size_t			time_start;
	t_philo			**philo;
	t_gb			*gb;
	pthread_t		*monitor;
	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*stop_m;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*lte;
}					t_a;

//====================MANIP_CHAR_CHAINE============//
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
long				ft_atol(const char *str);
int					check_value(char **av, int ac);
//==================================================//

//====================VALIDATION===================//
int					valid_args(int ac, char **av);
int					valid_start(int ac, char **av);
//==================================================//

//====================MEMORY_MANAGEMENT============//
void				*add_to_gb(t_gb *gb, void *ptr);
void				free_gb(t_gb *gb);
void				*new_malloc(t_a *a, size_t size);
void				free_all(t_a *a);
//==================================================//

//====================INITIALIZATION===============//
void				init_mutex(t_a *a);
void				init_philosophers(t_a *a);
void				init_struct(t_a *a, int ac, char **av);
void				init_mutex_2(t_a *a);
void				init_phi_2(t_a *a, int i);
//==================================================//

//====================THREAD_ROUTINES===============//
void				*routine(void *arg);
void				pthread_create_phi(t_a *a);
void				ft_usleep(size_t time_in_ms);
void				*monitoring(void *arg);
void				*monitoring_2(t_a *a, int i);
int					monitoring_3(t_a *a, int i);
//==================================================//

//====================PRINT_AND_CHECKS=============//
int					print_state(t_philo *philo, int state);
int					print_state_2(t_philo *philo, int state);
int					who_pick_the_fork(t_philo *philo);
int					check_death(t_a *a);
int					check_eat(t_a *a);
//==================================================//

//====================FORK_MANAGEMENT==============//
int					take_forks(t_philo *philo);
void				release_forks(t_philo *philo);
void				one_philo_one_fork(t_philo *philo);
//==================================================//

//====================MISCELLANEOUS=================//
void				*getback(t_philo *philo);
void				print_struct_philo(t_a *a);
//==================================================//

//====================TIME_RELATED_FUNCTIONS========//
size_t				gt(void);
size_t				cutime(t_a *a);
//==================================================//

//==================MUTEX==========================//
void				destroy_mutex(t_a *a);
//==================================================//

#endif
