/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:57:42 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/25 13:10:41 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 'A' || 'z' < str[index])
		{
			flag = 0;
			break ;
		}
		else if ('Z' < str[index] && str[index] < 'a')
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
