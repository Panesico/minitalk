/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:52:37 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 15:11:39 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	ft_if_null(int *boole, int c)
{
	if (!c)
	{
		ft_printf("\n");
		*boole = 1;
	}
	else
	{
		if (c != '\127')
		{
			ft_printf("%c", c);
			boole = 0;
		}
	}
}

void	ft_bits_to_char(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	cnt;
	static int	boole;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		c = c | (1 << cnt);
	cnt++;
	if (cnt == 8)
	{
		ft_if_null(&boole, c);
		if (boole)
			if (c == '\127')
				kill(info->si_pid, SIGUSR1);
		cnt = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_bits_to_char;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
