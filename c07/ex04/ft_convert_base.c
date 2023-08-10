/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:47:34 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/03 10:43:52 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(char *str, char *base, int digit);

char	*ft_putnbr(long long nbr, char *base, int digit, char *result)
{
	char	mod;

	while (nbr >= digit)
	{
		mod = base[nbr % digit];
		*result = mod;
		nbr /= digit;
		result--;
	}
	mod = base[nbr % digit];
	*result = mod;
	return (result);
}

int	ft_check_base(char *base)
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
		if (base[digit] == '+' || base[digit] == '-')
			return (0);
		if ((9 <= base[digit] && base[digit] <= 13) || base[digit] == 32)
			return (0);
		if (check_base[(int)base[digit]])
			return (0);
		check_base[(int)base[digit]] = 1;
		digit++;
	}
	if (digit <= 1)
		return (0);
	return (digit);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		number;
	char			*result_ptr;
	int				from_digit;
	int				to_digit;
	int				sign;

	from_digit = ft_check_base(base_from);
	to_digit = ft_check_base(base_to);
	result_ptr = (char *)malloc(sizeof(char) * 40);
	if (from_digit == 0 || to_digit == 0 || !result_ptr)
		return (0);
	result_ptr += 39;
	sign = 1;
	*result_ptr-- = '\0';
	number = ft_atoi(nbr, base_from, from_digit);
	if (number < 0)
	{
		number *= -1;
		sign *= -1;
	}
	result_ptr = ft_putnbr(number, base_to, to_digit, result_ptr);
	if (sign == -1 && number != 0)
		*(--result_ptr) = '-';
	return (result_ptr);
}
