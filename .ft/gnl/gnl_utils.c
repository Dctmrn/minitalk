/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:51:41 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/24 16:51:45 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_strrlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrjoin(char *s1, char *s2, size_t new_line)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	k;

	if (new_line)
		k = new_line;
	else
		k = ft_strrlen(s2);
	new = malloc(sizeof(char) * (ft_strrlen(s1) + k) + 1);
	if (!new)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	if (s1)
		while (s1[++i])
			new[i] = s1[i];
	else
		i++;
	while (++j < k)
	{
		new[i + j] = s2[j];
	}
	new[i + j] = '\0';
	return (free(s1), new);
}
