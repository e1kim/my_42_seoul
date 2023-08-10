/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:35:15 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/09 23:22:05 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

t_vec	ft_realloc(t_vec *vec, unsigned long long size)
{
	t_vec	new;

	if (!(vec->ptr))
	{
		new.ptr = malloc(sizeof(char *) * size);
		if (!new.ptr)
			exit (1);
		new.size = 0;
	}
	else
	{
		if (vec->capacity < size)
		{
			new.ptr = malloc(sizeof(char *) * size);
			if (!new.ptr)
				exit (1);
			ft_memcpy(new.ptr, vec->ptr, vec->capacity);
			new.size = vec->size;
			free(vec->ptr);
		}
		else
			return (*vec);
	}
	new.capacity = size;
	return (new);
}

t_vec	ft_save_read(int descriptor)
{
	char	temp[BUFF_SIZE];
	ssize_t	rd_size;
	t_vec	buff_v;

	buff_v.ptr = 0;
	buff_v = ft_realloc(&buff_v, BUFF_SIZE);
	while (1)
	{
		rd_size = read(descriptor, temp, BUFF_SIZE);
		if (rd_size <= 0)
			break ;
		if (buff_v.capacity < rd_size + buff_v.size)
		{
			buff_v = ft_realloc(&buff_v, (rd_size + buff_v.size) * 2);
			ft_memcat(buff_v.ptr, temp, buff_v.size, rd_size);
			buff_v.size += rd_size;
		}
		else
		{
			ft_memcat(buff_v.ptr, temp, buff_v.size, rd_size);
			buff_v.size += rd_size;
		}
	}
	buff_v.ptr[buff_v.size] = '\0';
	return (buff_v);
}

t_vec	ft_read_file(char *filename)
{
	int		fd;
	t_vec	ret;

	ret.capacity = 0;
	ret.size = 0;
	ret.ptr = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ret);
	ret = ft_save_read(fd);
	close(fd);
	return (ret);
}

t_vec	ft_read_stdin(void)
{
	t_vec	ret;

	ret.capacity = 0;
	ret.size = 0;
	ret.ptr = 0;
	ret = ft_save_read(0);
	return (ret);
}
