/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:46:56 by snuts             #+#    #+#             */
/*   Updated: 2021/11/24 21:11:03 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static void	ft_sigaction(int sig, siginfo_t *x, void *y)
{
	static int	current_bit = 7;
	static char	c = 0;

	(void) y;
	(void) x;
	if (sig == SIGUSR1)
		c = c | (1 << current_bit);
	current_bit--;
	if (current_bit == -1)
	{
		write(1, &c, 1);
		c = 0;
		current_bit = 7;
	}
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_fd(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_fd(n * (-1));
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd (n / 10);
		}
		ft_putchar(n % 10 + 48);
	}
}

int	main(void)
{
	struct sigaction	s_sig;

	write(1, "PID = ", 6);
	ft_putnbr_fd(getpid());
	write(1, "\n", 1);
	s_sig.sa_sigaction = ft_sigaction;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	while (1)
		pause();
	return (0);
}
