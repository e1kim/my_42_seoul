/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:57:12 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/30 17:57:26 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
int		number_to_input(int **input, char **argv);
int		input_data_error_case(int argc);
void	rush(int **input);
int		**ft_malloc(void);
void	ft_free(int **input);

int	main(int argc, char **argv)
{
	int		**input;
	int		i;
	int		j;

	if (input_data_error_case(argc))
		return (-1);
	input = ft_malloc();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			input[i][j] = 0;
			++j;
		}
		++i;
	}
	if (number_to_input(input, argv))
	{
		ft_putstr("Error\n");
		return (-1);
	}
	rush(input);
	ft_free(input);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	number_to_input(int **input, char **argv)
{
	int		i;
	int		j;
	char	next;

	i = 0;
	j = 0;
	while (j < 16)
	{
		if ('1' <= *(*(argv + 1) + i) && *(*(argv + 1) + i) <= '4')
		{
			next = *(*(argv + 1) + (i + 1));
			if (!(next == ' ' || next == '\0'))
				return (1);
			input[j / 4][j % 4] = *(*(argv + 1) + i) - '0';
			++j;
		}
		else if (' ' != *(*(argv + 1) + i))
			return (1);
		++i;
	}
	return (0);
}

int	input_data_error_case(int argc)
{
	if (!(argc == 2))
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
