#include "../includes/minitalk.h"

void ft_send_bits(char c, int pid)
{
	int	i;
	int bit;

	bit = 0;
	i = 7;
	while(i >= 0)
	{
		bit = (c & (1 << i) << i);
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int ft_loop_send_bits(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_send_bits(str[i], pid);
		usleep(50);
		i++;
	}
	if (!str[i])
	{
		ft_send_bits(str[i], pid);
	}
	return (0);
}

int main (int argc, char **argv)
{
	(void)argc;
	int pid;
	int i;

	pid = ft_atoi(argv[1]);
	i = 2;
	while (i < argc)
	{
		ft_loop_send_bits(argv[i], pid);
		i++;
	}
}