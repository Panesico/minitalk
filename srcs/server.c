#include "../includes/minitalk.h"

void	ft_bits_to_char(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	cnt;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		c = c << 1 | 1;
	else if (signal == SIGUSR2)
		c = c << 1;
	cnt++;
	if (cnt == 8)
	{
		ft_printf("%c", c);
		if (c == 0)
			ft_printf("\n");
		cnt = 0;
		c = 0;
	}
}

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct	sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_bits_to_char;
	ft_printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
		usleep(50);
	}
}