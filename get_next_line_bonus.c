/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:52:28 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/26 16:52:31 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stat_var[MAX_FD];
	char		*temp;
	char		*return_l;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stat_var[fd] = gnl_join_var(stat_var[fd], fd);
	if (!stat_var[fd])
		return (NULL);
	i = 0;
	while (stat_var[fd][i] != '\n' && stat_var[fd][i])
		i++;
	if (stat_var[fd][i] == '\n')
		i++;
	return_l = ft_gnl_substr(stat_var[fd], 0, i);
	if (!return_l)
		return (ft_free(&stat_var[fd]));
	temp = ft_gnl_substr(stat_var[fd], i, ft_strlen(stat_var[fd]) - i);
	ft_free(&stat_var[fd]);
	stat_var[fd] = temp;
	return (return_l);
}

char	*gnl_join_var(char *stat_var, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;

	i = 0;
	while (i <= BUFFER_SIZE)
		temp[i++] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (ft_free(&stat_var));
		temp[i] = '\0';
		if (!stat_var)
			stat_var = ft_strdup(temp);
		else
			stat_var = ft_gnl_strjoin(stat_var, temp);
		if (!stat_var)
			return (NULL);
	}
	return (stat_var);
}
