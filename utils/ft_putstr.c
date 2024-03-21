
#include "../minitalk.h"

int	ft_putstr(char *str)
{
	char	*s;
	int		i;
	int		len;

	len = 0;
	i = 0 ;
	if (str)
		s = str;
	else
		s = "(null)";
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}
