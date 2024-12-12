/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:32:34 by massrayb          #+#    #+#             */
/*   Updated: 2024/12/08 11:44:48 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line_size(char *str)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	copy_lv_to_line(char **lv, char **line)
{
	int	i;

	i = 0;
	*line = malloc(get_line_size(*lv) + 1);
	if (!*line)
		return (0);
	while ((*lv)[i])
	{
		(*line)[i] = (*lv)[i];
		if ((*lv)[i] == '\n')
		{
			(*line)[i + 1] = '\0';
			save_to_left_over(lv, i + 1);
			return (1);
		}
		i++;
	}
	(*line)[i] = '\0';
	free(*lv);
	*lv = NULL;
	return (0);
}

int	init_chars(char **line, char **buff, int fd)
{
	int	is_fail;

	is_fail = 0;
	*line = NULL;
	if (fd < 0 || read(fd, 0, 0) != 0 || fd > OPEN_MAX
		|| BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		is_fail = 1;
	*buff = malloc(BUFFER_SIZE);
	if (*buff && is_fail)
		free(*buff);
	return (is_fail);
}

char	*get_next_line_bonus(int fd)
{
	char			*line;
	char			*buff;
	static	char*	left_over[OPEN_MAX] = {NULL};
	int				size;

	if (init_chars(&line, &buff, fd) == 1)
		return (NULL);
	while (1)
	{
		if (left_over[fd])
		{
			if (copy_lv_to_line(&left_over[fd], &line) == 1)
				break ;
		}
		size = read(fd, buff, BUFFER_SIZE);
		if (size <= 0)
		{
			break ;
		}
		if (buff_to_line(&buff, &line, &(left_over[fd]), size))
			break ;
	}
	return (free(buff), line);
}
