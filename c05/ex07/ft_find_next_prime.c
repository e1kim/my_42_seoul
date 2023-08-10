/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:51:32 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/30 21:16:22 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime2(int nb)
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
	while (divisor * divisor < nb)
	{
		if (nb % divisor == 0)
		{
			return (0);
		}
		divisor++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	result;
	int	divisor;

	result = nb;
	divisor = 2;
	if (nb <= 1)
	{
		return (2);
	}
	if (ft_is_prime2(nb))
		return (nb);
	while (!ft_is_prime2(result))
	{
		result++;
	}
	return (result);
}
