/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 00:06:16 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 09:59:55 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_search(char **line, char *tmp, t_list *cl, long long int rd)
{
	if ((tmp = ft_strchr(cl->content, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(cl->content);
		if (!(tmp = ft_strdup(tmp + 1)) || !(*line))
			return (-1);
		free(cl->content);
		cl->content = tmp;
		return (1);
	}
	else if (rd == 0 && ft_strlen(cl->content))
	{
		*line = ft_strdup(cl->content);
		free(cl->content);
		if ((cl->content = ft_strnew(0)))
			return (*line ? 1 : -1);
		return (-1);
	}
	else if (rd == 0 && !ft_strlen(cl->content))
	{
		*line = NULL;
		return (0);
	}
	return (ft_gnl((int)cl->content_size, line));
}

int				ft_gnl(int const fd, char **line)
{
	static t_list	*start;
	t_list			*cl;
	char			*buff;
	long long int	rd;
	char			*tmp;

	start = start ? start : ft_lstnew("\0", 1);
	start->content_size = 0;
	cl = start;
	if (!(buff = malloc(BUFF_SIZE + 1)) || fd < 0 || !line
			|| (rd = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	while (cl->next && (int)cl->content_size != fd)
		cl = cl->next;
	if (!(buff[rd] = '\0') && (int)cl->content_size != fd)
	{
		cl->next = ft_lstnew("\0", 1);
		cl = cl->next;
		cl->content_size = (size_t)fd;
	}
	tmp = ft_strjoin(cl->content, buff);
	free(cl->content);
	free(buff);
	cl->content = tmp;
	return (gnl_search(line, tmp, cl, rd));
}
