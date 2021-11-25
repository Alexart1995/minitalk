/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:46:48 by snuts             #+#    #+#             */
/*   Updated: 2021/11/25 23:25:52 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

static int	min_max(unsigned long long int num, int min, const char *str)
{
	int	i;

	i = 0;
	if (*str <= '0' && *str >= '9')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 19 || num > 9223372036854775807)
	{
		if (min == 1)
			return (-1);
		else if (min == -1)
			return (0);
	}
	return (min * num);
}

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	num;
	int						min;

	min = 1;
	num = 0;
	i = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		&& str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		i++;
		min = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (min_max(num, min, str));
}

void	send_char(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if (str[i] & 1 << bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(400);
		}
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);
	send_char(pid, argv[2]);
	return (0);
}
