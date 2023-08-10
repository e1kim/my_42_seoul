/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:15:45 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/02 17:32:27 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*result;
	long long	size;
	long long	i;

	i = 0;
	if (min >= max || range == 0)
		return (0);
	size = max - min;
	result = (int *)malloc(sizeof(int) * (size));
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = i + min;
		i++;
	}
	*range = result;
	return (size);
}
