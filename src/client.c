#include "../includes/minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill (pid, SIGUSR1);
	else
		kill (pid, SIGUSR2);
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit (pid, bit);
		i--;
	}
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_char (pid, msg[i]);
		i++;
	}
	send_char (pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	send_msg (pid, argv[2]);
	return (0);
}
