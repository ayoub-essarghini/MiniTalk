#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define END_TRANSMISSION '\0'

/**
 *Checks if the signal is SIGUSR1. If it is, it will
 * assign 1 to the LSB. Else, it will assign 0 (actually it simply
 * won't modify it).
 *
 * Example:
 * 00101100   current_char
 * 00000001   result of (sigsent == SIGUSR1)
 * --------
 * 00101101   result stored in message after the bitwise OR operation
 *
 * It will then increment the bit index.
 * If it is 8, it means that
 * the char has been fully transmitted. It will then print it and
 * reset the bit index and the current char.
 * Else, it will shift the current char to the left by 1.
 *
 * 
 */
void	handle_signal(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			printf("\n");
		else
			printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}


int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}