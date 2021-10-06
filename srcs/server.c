/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 01:56:52 by gjacqual          #+#    #+#             */
/*   Updated: 2021/10/06 03:19:29 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	ft_signal_handler(int sig_nb, siginfo_t *sig_info, void *context)
{

}

static void	ft_putpid(void)
{
	int	pid;
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}


int	main(void)
{
	struct sigaction	action;
	int sig_check1;
	int sig_check2;

	ft_putpid();

	action.sa_sigaction = ft_signal_handler;
	action.sa_flags = SA_SIGINFO;

	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);

	sig_check1 = sigaction(SIGUSR1, &action, 0);
	if (sig_check1 != 0)
		ft_putstr_fd("Signal error!\n", 1);
	sig_check2 = sigaction(SIGUSR2, &action, 0);
	if (sig_check2 != 0)
		ft_putstr_fd("Signal error!\n", 1);

	while (1)
		pause();
	return (0);
}