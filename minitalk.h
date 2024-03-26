/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:17:01 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/03/26 21:17:10 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

int	ft_putnbr_u(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_atoi(const char *str);

#endif
