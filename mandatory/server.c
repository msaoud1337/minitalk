/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:26:46 by msaoud            #+#    #+#             */
/*   Updated: 2022/01/14 03:18:21 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum, siginfo_t *info, void *non)
{
	static unsigned char	c;
	static int				bits;
	static pid_t			clientpid;

	(void)non;
	if (clientpid != info->si_pid)
	{
		bits = 0;
		c = 0xff;
	}
	if (signum == SIGUSR2)
		c = c ^ 0x80 >> bits;
	else if (signum == SIGUSR1)
		c = c | 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0xff;
	}
	clientpid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("Server PID : %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
