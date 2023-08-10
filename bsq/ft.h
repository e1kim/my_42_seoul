/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwkim <eunwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:47:35 by jakoo             #+#    #+#             */
/*   Updated: 2023/08/09 23:22:05 by eunwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 4096

typedef struct s_max_coord
{
	int	size;
	int	row;
	int	col;
}	t_max;

typedef struct s_map_info
{
	int		length;
	int		width;
	char	print[3];
}	t_map;

typedef struct s_data
{
	char	**map;
	int		**tab;
}	t_data;

typedef struct vector
{
	unsigned long long		size;
	unsigned long long		capacity;
	char					*ptr;
}	t_vec;

t_vec	ft_read_file(char *filename);
t_vec	ft_read_stdin(void);
int		ft_atoi(char *str);
int		newline_strlen(char *str);
void	ft_put_error(char *str);
int		ft_width(t_vec buffer, int length, char *print);
int		ft_check(char *buffer, char *print);
void	map_init(char **map, char *buffer, int length);
int		**ft_tab_malloc(int length, int width, char *print, char **map);
void	ft_find_bsq(int length, int width, int **tab, t_max *info);
void	ft_print_sol(t_max info, char **sol, t_map hint);
int		ft_check_error(t_vec buffer, char *print, int *length, int *width);
char	**ft_malloc(int length, int width);
void	ft_malloc_and_init(t_data *data, t_map hint, char *buffer);
void	print_result(char **sol, int length, int width);
void	ft_memcpy(char *dest, char *src, unsigned long long n);
void	ft_memcat(char *dest, char *src, unsigned long long start, int size);
char	*ft_strncpy(char *src, unsigned int n);

#endif
