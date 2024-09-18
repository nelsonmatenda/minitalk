/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:53:08 by nfigueir          #+#    #+#             */
/*   Updated: 2024/09/18 14:29:34 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_handler(int signal)
{
	static char	c;
	static int	i;

	if (signal == SIGUSR2)
		c = (c * 2);
	else if (signal == SIGUSR1)
		c = ((c * 2) + 1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		c = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		exit(EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		;
	return (EXIT_SUCCESS);
}
