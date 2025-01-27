/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <mhanle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:06:12 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/26 16:53:22 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

char	*get_next_line(int fd);
char	*gnl_join_var(char *stat_var, int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char *s1, const char *s2);
char	*ft_gnl_substr(const char *s1, unsigned int start, size_t len);

#endif