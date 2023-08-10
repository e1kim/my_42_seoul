/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:30:17 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/09 18:00:41 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_memcpy(char *dest, char *src, unsigned long long n)
{
	char					*csrc;
	char					*cdest;
	unsigned long long		i;

	i = 0;
	csrc = src;
	cdest = dest;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
}

void	ft_memcat(char *dest, char *src, unsigned long long start, int size)
{
	char	*csrc;
	char	*cdest;
	int		index;

	index = 0;
	csrc = src;
	cdest = dest;
	while (index < size)
	{
		cdest[start + index] = csrc[index];
		index++;
	}
}

char	*ft_strncpy(char *src, unsigned int n)
{
	unsigned int	i;
	char			*result;

	result = (char *)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n && src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
