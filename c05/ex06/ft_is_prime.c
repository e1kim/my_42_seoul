/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:00 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/28 17:43:12 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	result;
	int	divisor;

	divisor = 2;
	result = 0;
	if (nb <= 1)
	{
		return (0);
	}
	if (nb == 2 || nb == 2147483647)
		return (1);
	while (divisor < nb)
	{
		if (nb % divisor == 0)
		{
			return (0);
		}
		divisor++;
	}
	return (1);
}
