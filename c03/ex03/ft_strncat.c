/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:51:05 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/27 09:57:09 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	index;

	i = 0;
	index = 0;
	if (nb == 0)
		return (dest);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (*src != '\0' && index < nb)
	{
		dest[i] = *src;
		i++;
		src++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}
