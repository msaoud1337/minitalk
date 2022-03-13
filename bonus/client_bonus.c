/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:51:35 by msaoud            #+#    #+#             */
/*   Updated: 2022/01/13 21:57:23 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sendingmessage(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (str[0] == '\0')
	{
		while (++i < 8)
		{
			kill(pid, SIGUSR2);
			usleep(1000);
		}
	}
	while (str[++j])
	{
		i = -1;
		while (++i < 8)
		{
			if ((str[j] & 128 >> i) != 0)
				kill(pid, SIGUSR1);
			else if ((str[j] & 128 >> i) == 0)
				kill(pid, SIGUSR2);
			usleep(1000);
		}
	}
}

void	printmessage(int walo)
{
	(void)walo;
	ft_printf("*****message received*****");
}

int	main(int arc, char *arv[])
{
	int	pid;

	pid = 0;
	signal(SIGUSR1, printmessage);
	if (arc == 3)
	{
		pid = ft_atoi(arv[1]);
		if (pid <= 0)
			return (0);
		sendingmessage(arv[2], pid);
		sendingmessage("", pid);
	}
	return (0);
}
