/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:24:24 by lberthal          #+#    #+#             */
/*   Updated: 2024/05/30 00:50:27 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//-------------------------------------LIBFT_H-------------------------------//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_tolower(int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_lstadd_back(t_list **lst, t_list *lstnew);
void				ft_lstadd_front(t_list **lst, t_list *lstnew);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//--------------------------------------------------------------------------//

//---------------------------------PRINTF---------------------------------//
typedef struct s_pf
{
	int				cp;
	int				neg;
	char			*s;

}					t_pf;

int					selection(char c, va_list args, t_pf *pf);
int					ft_printf(const char *s, ...);
int					string(va_list args, t_pf *pf);
int					decimale(va_list args, t_pf *pf);
int					integer(va_list args, t_pf *pf);
int					unsinged_decimale(va_list args, t_pf *pf);
int					putnbr(long int i, t_pf *pf);
int					character(va_list args, t_pf *pf);
int					hexa_lower(unsigned long long i, char *base, t_pf *pf);
int					hexa_upper(unsigned long long i, char *base, t_pf *pf);
int					pointer(unsigned long long i, char *base, t_pf *pf);
int					hexa_bases(va_list args, char c, t_pf *pf);
int					count(long int i);
int					count_hex(unsigned long long int i);
int					write_char_tab(va_list args, t_pf *pf);
int					char_tab(char **tab, t_pf *pf);
int					char_tab_big(char **tab, t_pf *pf, int count);
int					count_tab(char **tab);

//---------------------------------------------------------------------------//

//--------------------------------FPRINTF---------------------------------//

typedef struct s_fpf
{
	int				cp;
	int				neg;
	char			*s;
	int				fd;

}					t_fpf;

int					ft_fprintf(int fd, const char *s, ...);
int					fselection(char c, va_list args, t_fpf *fpf);
int					fstring(va_list args, t_fpf *fpf);
int					fdecimale(va_list args, t_fpf *fpf);
int					finteger(va_list args, t_fpf *fpf);
int					funsinged_decimale(va_list args, t_fpf *fpf);
int					fputnbr(long int i, t_fpf *fpf);
int					fcharacter(va_list args, t_fpf *fpf);
int					fhexa_lower(unsigned long long i, char *base, t_fpf *fpf);
int					fhexa_upper(unsigned long long i, char *base, t_fpf *fpf);
int					fpointer(unsigned long long i, char *base, t_fpf *fpf);
int					fhexa_bases(va_list args, char c, t_fpf *fpf);
int					fwrite_char_tab(va_list args, t_fpf *fpf);
int					fcount(long int i);
int					fcount_hex(unsigned long long int i);

//-----------------------------GET_NEXT_LINE--------------------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	int				fd;
	int				rid;
	char			*str_stock;
	char			*n_ptr;
}					t_gnl;

char				*get_next_line(int fd);
void				ft_bzero_gnl(char *buffer);
int					ft_strlen_gnl(char *str);
char				*mm_gnl(char *dest, char *src, size_t n);//memmove
size_t				ft_strlcpy_gnl(char *dst, char *src, size_t size);
size_t				ft_strlcat_gnl(char *dest, char *src, size_t size,
						t_gnl *g);
int					ft_find_slash(t_gnl *g, char *buffer);
int					ft_strjoin_gnl(t_gnl *g, char *buffer);
int					reader(t_gnl *g, char *buffer);
int					slash_not_found(t_gnl *g, char *buffer);

//---------------------------------------------------------------------------//

//---------------------------------TEST_MALLOC_READ---------------------//

void				*ox_m(size_t xxx);
size_t				ox_r(int fdp, void *b, int len);
void				free_ptr(void *ptr);
void				free_double_ptr(char **ptr, int size);

#endif
