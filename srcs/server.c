/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:57:07 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 13:55:39 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_bits_to_char(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	cnt;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		c = c | (1 << cnt);
	cnt++;
	if (cnt == 8)
	{
		ft_printf("%c", c);
		if (!c)
			ft_printf("\n");
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
