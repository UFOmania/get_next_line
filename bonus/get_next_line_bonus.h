/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massrayb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:27:44 by massrayb          #+#    #+#             */
/*   Updated: 2024/12/08 11:23:20 by massrayb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

int			get_line_size(char *str);
int			copy_lv_to_line(char **lv, char **line);
int			buff_to_line(char **buff, char **line, char **lv, int read_size);
void		extend_line(char **line, int new_size);
char		*get_next_line_bonus(int fd);
void		save_to_left_over(char **lv, int start);

#endif