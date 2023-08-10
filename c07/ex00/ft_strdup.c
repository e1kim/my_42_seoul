/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:54:08 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/31 16:05:27 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	size = ft_strlen(src);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	while (i < size)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
