/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:34:27 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/07 09:51:21 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	do_plus(int first, int second);
void	do_minus(int first, int second);
void	do_division(int first, int second);
void	do_remain(int first, int second);
void	do_multiply(int first, int second);

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	write(1, str, n);
}

void	ft_work(int first, int second, char operator)
{
	int		i;
	void	(*ft[5])(int, int);

	i = 0;
	ft[0] = do_plus;
	ft[1] = do_minus;
	ft[2] = do_division;
	ft[3] = do_remain;
	ft[4] = do_multiply;
	if (operator == '+')
		(*ft[0])(first, second);
	else if (operator == '-')
		(*ft[1])(first, second);
	else if (operator == '/')
		(*ft[2])(first, second);
	else if (operator == '%')
		(*ft[3])(first, second);
	else if (operator == '*')
		(*ft[4])(first, second);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	int		first;
	int		second;
	char	operator;

	if (argc != 4)
		return (1);
	first = ft_atoi(argv[1]);
	second = ft_atoi(argv[3]);
	operator = argv[2][0];
	if (argv[2][1] != '\0')
		write(1, "0", 1);
	else
		ft_work(first, second, operator);
	write(1, "\n", 1);
	return (0);
}
