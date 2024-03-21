
#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_u(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_atoi(const char *str);

#endif
