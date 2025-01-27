/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:52:41 by mhanle            #+#    #+#             */
/*   Updated: 2024/11/26 16:52:44 by mhanle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 142
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

char	*get_next_line(int fd);
char	*gnl_join_var(char *stat_var, int fd);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char *s1, const char *s2);
char	*ft_gnl_substr(const char *s1, unsigned int start, size_t len);

#endif
