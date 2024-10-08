/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:21:18 by marida-c          #+#    #+#             */
/*   Updated: 2023/11/20 17:21:22 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			count += ft_print_char(str[count]);
			i++;
		}	
	}
	else
		count += ft_print_str("(null)");
	return (count);
}
