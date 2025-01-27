/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <mhanle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:05:30 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/22 19:36:34 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stat_var;
	char		*temp;
	char		*return_l;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stat_var = gnl_join_var(stat_var, fd);
	if (!stat_var)
		return (NULL);
	i = 0;
	while (stat_var[i] != '\n' && stat_var[i])
		i++;
	if (stat_var[i] == '\n')
		i++;
	return_l = ft_gnl_substr(stat_var, 0, i);
	if (!return_l)
		return (ft_free(&stat_var));
	temp = ft_gnl_substr(stat_var, i, ft_strlen(stat_var) - i);
	ft_free(&stat_var);
	stat_var = temp;
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
