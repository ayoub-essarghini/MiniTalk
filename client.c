/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:18:39 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/03/26 21:19:07 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_running_proc(pid_t pid)
{
	return (kill(pid, 0) == 0);
}

void	transmit_sig(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = c;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
	}
}

int	main(int ac, char **argv)
{
	pid_t		pid;
	const char	*message;
	int			i;

	if (ac != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	if (!is_running_proc(pid) || pid <= 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(1);
	}
	message = argv[2];
	i = 0;
	while (message[i])
		transmit_sig(pid, message[i++]);
	transmit_sig(pid, '\0');
	return (0);
}
