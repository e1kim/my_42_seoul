/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:35:17 by eunwkim           #+#    #+#             */
/*   Updated: 2023/08/07 09:46:35 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (!flag)
				flag = 1;
			if (flag == -1)
				return (0);
		}
		else if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (!flag)
				flag = -1;
			if (flag == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
