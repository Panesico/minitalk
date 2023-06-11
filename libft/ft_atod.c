/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:30:52 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 13:59:42 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_negative(const char *str, int *negative, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			*negative += 1;
		}
		*i += 1;
	}
}

double	ft_recursive_get_decimal(const char *str, int i, double num2)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		num2 = ft_recursive_get_decimal(str, i + 1, num2);
		if (str[i] >= '0' && str[i] <= '9')
			num2 = (num2 + (str[i] - 48)) / 10.0;
	}
	return (num2);
}

double	ft_atod(const char *str)
{
	int		i;
	int		negative;
	double	num;
	double	num2;

	i = 0;
	negative = 0;
	num = 0;
	num2 = 0;
	while (ft_isspace(str[i]))
		i++;
	ft_if_negative(str, &negative, &i);
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	num2 = ft_recursive_get_decimal(str, i, num2);
	num += num2;
	if (negative)
		num *= -1;
	return (num);
}
