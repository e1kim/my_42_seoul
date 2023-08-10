/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:10:57 by eunwkim           #+#    #+#             */
/*   Updated: 2023/07/26 16:21:11 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num_or_alpha(char s)
{
	if ('0' <= s && s <= '9')
	{
		return (1);
	}
	else if ('a' <= s && s <= 'z')
	{
		return (2);
	}
	else if ('A' <= s && s <= 'Z')
	{
		return (3);
	}
	else
		return (0);
}

void	ft_alpha(int *first, int flag, char *a)
{
	if (*first && flag == 2)
	{
		*a -= 32;
	}
	else if (!(*first) && flag == 3)
	{
		*a += 32;
	}
	*first = 0;
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	int		first;
	int		flag;

	index = 0;
	first = 1;
	while (str[index] != '\0')
	{
		flag = is_num_or_alpha(str[index]);
		if (flag == 0)
			first = 1;
		else
		{
			ft_alpha(&first, flag, &str[index]);
		}
		index++;
	}
	return (str);
}
