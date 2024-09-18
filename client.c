/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:13:50 by nfigueir          #+#    #+#             */
/*   Updated: 2024/09/18 14:03:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	msg_err(char *s)
{
	ft_printf("Error: %s.\n", s);
	exit(EXIT_FAILURE);
}

static void	send_bits(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1) == 1)
		{
			if ((kill(pid, SIGUSR1)) == -1)
				msg_err("Something wrong with signal SIGUSR1!");
		}
		else
		{
			if ((kill(pid, SIGUSR2)) == -1)
				msg_err("Something wrong with signal SIGUSR1!");
		}
		usleep(100);
	}
}

static int	parsing(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_strchr("0123456789", av[1][i]))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = -1;
	if (parsing(ac, av))
		msg_err("Try ./client <PID> <MESSAGE>");
	pid = ft_atoi(av[1]);
	while (av[2][++i] != '\0')
		send_bits(pid, av[2][i]);
	send_bits(pid, '\0');
	return (EXIT_SUCCESS);
}
