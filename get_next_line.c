/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:02:01 by lulebugl          #+#    #+#             */
/*   Updated: 2019/10/18 14:45:52 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char **line, char *buf, int i)
{
	int			st;

	i = 0;
	st = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		st = 1;
		buf[i] = '\0';
	}
	if (!(*line = ft_strjoin(*line, buf)))
		return (-1);
	if (st == 1)
		buf[i] = '\n';
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			val[2];

	if ((fd < 0 || !line) || !(*line = ft_strdup("")))
		return (-1);
	val[0] = 1;
	while (val[0])
	{
		if (!(*buf))
		{
			if ((val[0] = read(fd, buf, BUFFER_SIZE)) == 0 && **line)
				return (1);
			else if (val[0] < 0)
				return (-1);
		}
		if ((val[1] = ft_line(line, buf, val[1])) == -1)
			return (-1);
		if (buf[val[1]] == '\n')
		{
			ft_strncpy(buf, buf + val[1] + 1, BUFFER_SIZE);
			return (1);
		}
		ft_strncpy(buf, buf + val[1], BUFFER_SIZE);
	}
	return (0);
}
