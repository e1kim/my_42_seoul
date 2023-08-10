/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:39:31 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/01 14:51:40 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_sign(char a)
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
	return (0);
}

int	check_space_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (is_sign(str[i]))
	{
		if (is_sign(str[i]) == 2)
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str, char *base, int digit)
{
	int	i;
	int	sign;
	int	result;
	int	num;

	sign = 1;
	result = 0;
	i = check_space_and_sign(str, &sign);
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
