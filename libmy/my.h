/*
** my.h for libmy_small in my.h
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 12:09:44 2016 Maxime Louet
** Last update Wed Nov 16 12:09:44 2016 Maxime Louet
*/

#ifndef MY_H_
# define MY_H_

# include <stddef.h>
# include <stdarg.h>
# include <stdbool.h>

# define MYPRINTF_FLAGS_NB 7

typedef struct	s_pf_fts
{
  char		flag;
  char		pad[7];
  void		(*p)(int fd, va_list ap);
}		t_pf_fts;

void	pf_decintsigned(int fd, va_list ap);
void	pf_decintunsigned(int fd, va_list ap);
void	pf_percent(int fd, va_list ap);
void	pf_character(int fd, va_list ap);
void	pf_pointer(int fd, va_list ap);
void	pf_string(int fd, va_list ap);

int	my_dprintf(int fd, const char *format, ...);
int	my_printf(const char *format, ...);
int	my_vdprintf(int fd, const char *format, va_list ap);

int		my_atoi(const char *str);
char		*my_basename(char *str);
void		*my_calloc(size_t count, size_t size);
char		*my_concat(const char *s1, const char *s2);
int		my_extcmp(const char *path, const char *ext);
void		my_free_wt(char **wt);
char		*my_gnl(int fd);
int		my_isalnum(int c);
int		my_isalpha(int c);
int		my_isdigit(int c);
int		my_isspace(int c);
char		*my_itoa(int nb);
void		*my_memset(void *s, int c, size_t n);
size_t		my_nbrlen(long int nb);
void		my_print_wt(char **wt);
void		my_putchar(int c);
void		my_putchar_fd(int fd, int c);
void		my_putnbr(long int nb);
void		my_putnbr_base(long int nb, const char *base);
void		my_putnbr_base_fd(int fd, long int nb, const char *base);
void		my_putnbr_fd(int fd, long int nb);
void		my_putnstr(const char *str, size_t n);
void		my_putnstr_fd(int fd, const char *str, size_t n);
void		my_putstr(const char *str);
void		my_putstr_fd(int fd, const char *str);
char		*my_revstr(char *str);
int		my_str_isalnum(const char *str);
int		my_str_isdigit(const char *str);
char		**my_str_to_wt(const char *str, char delimiter);
char		*my_strcat(char *dest, const char *src);
char		*my_strchr(const char *s, int c);
int		my_strcmp(const char *s1, const char *s2);
char		*my_strcpy(char *dest, const char *src);
char		*my_strdup(const char *str);
size_t		my_strlen(const char *str);
int		my_strncmp(const char *s1, const char *s2, size_t n);
char		*my_strncpy(char *dest, const char *src, size_t n);
char		*my_strndup(const char *s, size_t n);
size_t		my_strnlen(const char *str, size_t n);
char		my_tolower(int c);
char		my_toupper(int c);
char		**my_wtdup(char **wt);
size_t		my_wtlen(char **wt);

#endif /* !MY_H_ */
