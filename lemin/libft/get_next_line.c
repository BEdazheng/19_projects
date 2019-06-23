/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikorale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:25:39 by mikorale          #+#    #+#             */
/*   Updated: 2019/01/04 13:25:20 by mikorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_sub(char *dst, char *src)
{
	long	len;
	long	i;

	len = 0;
	while (src[len])
		len++;
	if (!(dst = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	isline_next(char **data, char *tmp, char **line, int fd)
{
	int	i;

	i = 0;
	while (data[fd][i])
	{
		if (data[fd][i] == '\n')
		{
			data[fd][i] = '\0';
			*line = ft_strdup(data[fd]);
			tmp = my_sub(tmp, data[fd] + i + 1);
			free(data[fd]);
			data[fd] = tmp;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	isline(char **data, char *buf, char **tmp, int fd)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			data[fd] = my_strcat(data[fd], *tmp);
			free(*tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*d[10000];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	tmp = NULL;
	if (fd < 0 || BUFF_SIZE < 1 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	if (d[fd] && isline_next(d, tmp, line, fd) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = my_strcat(tmp, buf);
		if (isline(d, buf, &tmp, fd) == 1)
			return (isline_next(d, tmp, line, fd));
	}
	if ((d[fd] && d[fd][0]) || tmp)
	{
		*line = (d[fd] && d[fd][0]) ? ft_strdup(d[fd]) : my_strcat(*line, tmp);
		ft_strdel(&d[fd]);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}
