/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:11:45 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/10 10:15:50 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_free(void **input1, void **input2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(input1[i]);
		++i;
	}
	free(input1);
	i = 0;
	while (i < n)
	{
		free(input2[i]);
		++i;
	}
	free(input2);
}

t_vec	ft_start_read(int *argc, char **argv, int count)
{
	t_vec	buffer;

	if (*argc == 1)
		buffer = ft_read_stdin();
	else
	{
		if (count == 0)
			(*argc)--;
		buffer = ft_read_file(argv[count + 1]);
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	t_vec	buffer;
	int		count;
	t_max	info;
	t_map	hint;
	t_data	data;

	count = 0;
	while (count < argc)
	{
		buffer = ft_start_read(&argc, argv, count);
		if (!ft_check_error(buffer, hint.print, &(hint.length), &(hint.width)))
		{
			ft_malloc_and_init(&data, hint, buffer.ptr);
			ft_find_bsq(hint.length, hint.width, data.tab, &info);
			ft_print_sol(info, data.map, hint);
			ft_free((void **)data.map, (void **)data.tab, hint.length + 1);
		}
		else
			ft_put_error("map error\n");
		count++;
		if (count != argc)
			write(1, "\n", 1);
		free(buffer.ptr);
	}
	return (0);
}
