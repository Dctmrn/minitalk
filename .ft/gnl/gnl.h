/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:47:06 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/24 16:56:40 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 42

char	*ft_strrjoin(char *s1, char *s2, size_t new_line);
int		ft_strrlen(const char *s);
char	*get_next_line(int fd);

#endif
