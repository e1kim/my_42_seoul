/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:00:03 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/31 19:47:08 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_number(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == a)
			return (i);
		i++;
	}
	return (-1);
}

int	is_space(char a)
{
	if ((9 <= a && a <= 13) || a == 32)
		return (1);
	return (0);
}

int	is_sign_or_space(char a)
{
	if (a == '+' || a == '-')
	{
		if (a == '-')
		{
			return (2);
		}
		else
			return (1);
	}
	else if (is_space(a))
		return (3);
	return (0);
}

int	ft_atoi(char *str, char *base, int digit)
{
	int	i;
	int	sign;
	int	result;
	int	num;

	i = 0;
	sign = 1;
	result = 0;
	while (is_sign_or_space(str[i]))
	{
		if (is_sign_or_space(str[i]) == 2)
			sign *= -1;
		i++;
	}
	while (1)
	{
		num = is_number(str[i], base);
		if (num < 0)
			break ;
		result *= digit;
		result += num;
		i++;
	}
	return (sign * result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	digit;
	int	check_base[256];
	int	i;

	i = 0;
	digit = 0;
	while (i < 256)
	{
		check_base[i] = 0;
		i++;
	}
	while (base[digit] != '\0')
	{
		if (base[digit] == '+' || base[digit] == '-' || is_space(base[digit]))
			return (0);
		if (check_base[(int)base[digit]])
			return (0);
		check_base[(int)base[digit]] = 1;
		digit++;
	}
	if (digit <= 1)
		return (0);
	return (ft_atoi(str, base, digit));
}
