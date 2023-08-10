/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:34:36 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/05 19:35:28 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char a)
{
	if (('0' <= a && a <= '9'))
		return (1);
	return (0);
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

int	is_space(char a)
{
	if ((9 <= a && a <= 13) || a == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	while (is_sign(str[i]))
	{
		if (is_sign(str[i]) == 2)
			sign *= -1;
		i++;
	}
	while (is_number(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (sign * result);
}
