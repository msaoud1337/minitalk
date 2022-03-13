/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaoud <msaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:26:39 by msaoud            #+#    #+#             */
/*   Updated: 2022/01/13 22:39:53 by msaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendingmessage(char *str, int pid)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
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

int	main(int arc, char *arv[])
{
	int	pid;

	pid = 0;
	if (arc == 3)
	{
		pid = ft_atoi(arv[1]);
		if (pid <= 0)
			return (0);
		sendingmessage(arv[2], pid);
	}
	return (0);
}
