/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:20:29 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/03/26 21:20:31 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	is_running_proc(pid_t pid)
{
	return (kill(pid, 0) == 0);
}

void	send_signal(int pid, unsigned char c)
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

void	handle_response(int res)
{
	if (res == SIGUSR1)
		ft_printf("\033[0;32m message sent successfully !\033[0m\n");
}

int	main(int ac, char **argv)
{
	pid_t		pid;
	const char	*message;
	int			i;

	signal(SIGUSR1, handle_response);
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
		send_signal(pid, message[i++]);
	send_signal(pid, '\0');
	return (0);
}
