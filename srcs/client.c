/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:47:41 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 13:47:41 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_send_bits(char c, int pid)
{
	int	i;
	int	bit;

	bit = 0;
	i = 0;
	while (i < 8)
	{
		bit = (c & (1 << i));
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	ft_loop_send_bits(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bits(str[i], pid);
		i++;
	}
	ft_send_bits(0, pid);
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc > 1)
		pid = ft_atoi(argv[1]);
	i = 2;
	while (i < argc)
	{
		ft_loop_send_bits(argv[i], pid);
		i++;
	}
}
