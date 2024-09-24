/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:13:36 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/24 15:52:45 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int		g_confirmation;

void	char_to_bit(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_confirmation)
			;
		g_confirmation = 0;
		bit--;
		if (c == '\0' && bit == 0)
			ft_printf("Message received\n");
	}
}

void	signal_confirmation(int sig)
{
	(void)sig;
	g_confirmation = 1;
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Argument error : try ./client <PID> <Message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_putstr("PID invalid\n");
		return (1);
	}
	message = argv[2];
	signal(SIGUSR1, signal_confirmation);
	while (*message)
		char_to_bit(pid, *message++);
	char_to_bit(pid, '\0');
	return (0);
}
