#ifndef MINITALK_H
# define MINITALK_H

#include "../.ft/gnl/gnl.h"
#include "../.ft/libft/libft.h"
#include "../.ft/printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>

void	signal_confirmation(int sig);
void	char_to_bit(pid_t pid, char c);
void	handle_signal(int sig, siginfo_t *info, void *context);



#endif