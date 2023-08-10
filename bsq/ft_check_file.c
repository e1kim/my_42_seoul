/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:15:59 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/10 12:30:04 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	newline_strlen(char *str)
{
	int	number;

	number = 0;
	while (str[number] != '\n' && str[number] != '\0')
	{
		number++;
	}
	return (number);
}

void	ft_put_error(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	write(2, str, n);
}

int	ft_width(t_vec buffer, int length, char *print)
{
	int		width;
	int		temp_width;
	int		i;
	char	*ptr;

	i = 0;
	ptr = buffer.ptr + newline_strlen(buffer.ptr) + 1;
	while (i < length)
	{
		temp_width = 0;
		while (*ptr != '\n' && *ptr != '\0')
		{
			if (!(*ptr == print[0] || *ptr == print[1]))
				return (0);
			ptr++;
			temp_width++;
		}
		if (*ptr == '\0' || (i++ >= 2 && temp_width != width))
			return (0);
		width = temp_width;
		ptr++;
	}
	if (*ptr != '\0')
		return (0);
	return (width);
}

int	ft_check(char *buffer, char *print)
{
	int		pre_len;
	int		length;
	char	*temp_atoi;

	pre_len = newline_strlen(buffer);
	if (pre_len < 4)
		return (0);
	print[0] = buffer[pre_len - 3];
	print[1] = buffer[pre_len - 2];
	print[2] = buffer[pre_len - 1];
	if (print[0] == print[1] || print[1] == print[2] || print[0] == print[2])
		return (0);
	temp_atoi = ft_strncpy(buffer, pre_len - 3);
	length = ft_atoi(temp_atoi);
	free(temp_atoi);
	if (length <= 0)
		return (0);
	return (length);
}

int	ft_check_error(t_vec buffer, char *print, int *length, int *width)
{
	int	f_line;
	int	cal_size;

	if (!buffer.ptr)
		return (1);
	f_line = newline_strlen(buffer.ptr) + 1;
	*length = ft_check(buffer.ptr, print);
	if (!(*length))
		return (1);
	*width = ft_width(buffer, *length, print);
	if (!(*width))
		return (1);
	cal_size = (*width + 1) * (*length) + f_line;
	if ((unsigned long long)(cal_size) != buffer.size)
		return (1);
	return (0);
}
