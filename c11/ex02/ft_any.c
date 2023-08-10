/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:02:12 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/06 13:12:48 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	flag;
	int	count;
	int	i;

	count = 0;
	while (tab[count] != 0)
	{
		count++;
	}
	flag = 0;
	i = 0;
	while (i < count)
	{
		flag = (*f)(tab[i]);
		if (flag)
			return (1);
		i++;
	}
	return (0);
}
