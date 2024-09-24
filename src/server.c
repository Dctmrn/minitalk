/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marida-c <marida-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:13:51 by marida-c          #+#    #+#             */
/*   Updated: 2024/09/24 15:53:29 by marida-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bits = 0;
	static unsigned char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
