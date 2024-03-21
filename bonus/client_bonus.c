#include "../minitalk.h"

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
		usleep(420);
	}
}


void	handle_response(int rep)
{
	if (rep == SIGUSR1)
		ft_printf("1\n");
	else if (rep == SIGUSR2)
		ft_printf("0\n");
}


int	main(int ac, char **argv)
{
	int		server_pid;
	const char	*message;
	int			i;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}