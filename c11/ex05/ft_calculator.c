/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:26:26 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/06 18:59:13 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	do_plus(int first, int second)
{
	ft_putnbr(first + second);
}

void	do_minus(int first, int second)
{
	ft_putnbr(first - second);
}

void	do_division(int first, int second)
{
	if (second == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(first / second);
}

void	do_remain(int first, int second)
{
	if (second == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(first % second);
}

void	do_multiply(int first, int second)
{
	ft_putnbr(first * second);
}
