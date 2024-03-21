#include "minitalk.h"

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
		usleep(300);
	}
}

int	main(int ac, char **argv)
{
	int		pid;
	const char	*message;
	int			i;

	if (ac != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		transmit_sig(pid, message[i++]);
	transmit_sig(pid, '\0');
	return (0);
}