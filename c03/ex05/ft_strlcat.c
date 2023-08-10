/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:24:07 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/27 10:13:54 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	i;
	unsigned int	dest_c;
	unsigned int	src_c;

	index = 0;
	dest_c = ft_strlen(dest);
	src_c = ft_strlen(src);
	i = dest_c;
	if (size != 0)
	{
		while (*src != '\0' && index + dest_c < size - 1)
		{
			dest[i] = *src;
			src++;
			i++;
			index++;
		}
		dest[i] = '\0';
	}
	if (dest_c < size)
		return (dest_c + src_c);
	else
		return (src_c + size);
}
