/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:57:52 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/27 15:34:53 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	j;
	char			*result;

	if (*to_find == '\0')
		return (str);
	j = 0;
	result = str;
	while (*str != '\0' && to_find[j] != '\0')
	{
		if (*str == to_find[j])
		{
			if (j == 0)
				result = str;
			j++;
		}
		else
		{
			j = 0;
		}
		str++;
	}
	if (j && to_find[j] == '\0')
		return (result);
	else
		return (0);
}
