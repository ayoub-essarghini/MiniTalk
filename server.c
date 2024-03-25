#include "minitalk.h"

void sig_handler(int sig)
{
	static unsigned char current_char;
	static int i;

	current_char |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int main(void)
{
	ft_printf("%d\n", getpid());
	struct sigaction sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}