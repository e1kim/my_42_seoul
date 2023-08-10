/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:40:16 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/03 14:43:02 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	check(char a, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == a)
		{
			return (1);
		}
		charset++;
	}
	if (*charset == '\0' && a == '\0')
		return (1);
	return (0);
}

int	count_words(char *src, char *charset)
{
	int		count;
	char	*prev;
	char	*next;

	count = 0;
	prev = src;
	next = src;
	while (1)
	{
		if (check(*src, charset))
			next = src;
		if (next - prev > 1 || (next - prev > 0 && !check(prev[0], charset)))
			count++;
		if (*src == '\0')
			break ;
		prev = next;
		src++;
	}
	return (count);
}

void	put_words(char *next, char *prev, char *charset, char **result)
{
	int	size;

	if (check(prev[0], charset))
		prev++;
	size = next - prev;
	(*result) = (char *)malloc((size + 1) * sizeof(char));
	if (!(*result))
		return ;
	ft_strncpy(*result, prev, size);
	(*result)[size] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*prev;
	char	*next;
	int		i;

	prev = str;
	next = str;
	i = 0;
	result = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (1)
	{
		if (check(*str, charset))
			next = str;
		if (next - prev > 1 || (next - prev > 0 && !check(prev[0], charset)))
			put_words(next, prev, charset, &result[i++]);
		if (*str == '\0')
			break ;
		str++;
		prev = next;
	}
	result[i] = NULL;
	return (result);
}
