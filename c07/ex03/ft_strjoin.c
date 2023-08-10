/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:38:31 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/02 19:58:38 by eunwkim          ###   ########.fr       */
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

int	ft_total_length(int size, char **strs, char *sep)
{
	int	sep_length;
	int	total_length;
	int	i;

	total_length = 0;
	i = 0;
	sep_length = ft_strlen(sep);
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		if (i != size - 1)
			total_length += sep_length;
		i++;
	}
	return (total_length);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		length;
	int		i;

	if (size == 0)
	{
		result = malloc(sizeof(char) * 1);
		*result = 0;
		return (result);
	}
	length = ft_total_length(size, strs, sep) + 1;
	result = (char *)malloc(sizeof(char) * length);
	if (!result)
		return (0);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
