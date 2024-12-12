/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:32:45 by massrayb          #+#    #+#             */
/*   Updated: 2024/12/08 11:24:21 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	save_to_left_over(char **lv, int start)
{
	char	*new_lv;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_lv = NULL;
	while ((*lv)[i + start])
		i++;
	if (i > 0)
		new_lv = malloc(i + 1);
	while (new_lv && (*lv)[start] && i > 0)
	{
		new_lv[j] = (*lv)[start];
		start++;
		j++;
	}
	if (new_lv)
		new_lv[j] = '\0';
	free(*lv);
	*lv = new_lv;
}

void	extend_line(char **line, int new_size)
{
	int		i;
	char	*res;

	i = 0;
	if (!(*line))
	{
		*line = malloc(new_size + 1);
		if (!(*line))
			*line = NULL;
		else
			*line[0] = '\0';
	}
	else
	{
		while ((*line)[i])
			i++;
		i++;
		res = malloc(new_size + i);
		while (res && i-- > 0)
			res[i] = (*line)[i];
		free(*line);
		*line = res;
	}
}

static void	buff_to_left_over(char **buff, char **lv, int start, int size)
{
	int	i;

	i = 0;
	*lv = NULL;
	*lv = malloc(size - start + 1);
	if (!*lv)
		return ;
	while (start < size)
	{
		(*lv)[i] = (*buff)[start];
		start++;
		i++;
	}
	(*lv)[i] = '\0';
}

static int	b_to_l_helper(char *line, int *is_done)
{
	int	i;

	i = 0;
	if (!line)
		*is_done = 1;
	while (line && line[i])
		i++;
	return (i);
}

int	buff_to_line(char **buff, char **line, char **lv, int read_size)
{
	int	i;
	int	j;
	int	is_done;

	i = 0;
	j = -1;
	is_done = 0;
	extend_line(line, get_line_size(*buff));
	i = b_to_l_helper(*line, &is_done);
	while (*line && ++j < read_size)
	{
		(*line)[i++] = (*buff)[j];
		if ((*buff)[j] == '\n')
		{
			if (j < read_size - 1)
				buff_to_left_over(buff, lv, j + 1, read_size);
			is_done = 1;
			break ;
		}
	}
	if (*line)
		(*line)[i] = '\0';
	return (is_done);
}
