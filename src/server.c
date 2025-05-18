#include "../includes/minitalk.h"

void	catch_signal(int signal)
{
	static t_data	data;

	data.chr = data.chr << 1;
	if (signal == SIGUSR2)
		data.chr = data.chr | 1;
	data.count_bits++;
	if (data.count_bits == 8)
	{
		if (data.chr == 0)
			ft_printf("\n");
		else
			ft_printf("%c", data.chr);
		data.count_bits = 0;
		data.chr = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, catch_signal);
	signal(SIGUSR2, catch_signal);
	while (1)
		pause();
	return (0);
}
