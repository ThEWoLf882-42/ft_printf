/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:54:56 by agimi             #+#    #+#             */
/*   Updated: 2022/10/26 12:01:04 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	action(const char *select, va_list argp, int i)
{
	int	hsab;

	hsab = 0;
	if (select[i] == '%' && select[i + 1] == 'c')
		hsab += ft_putchar(va_arg(argp, int));
	else if (select[i] == '%' && select[i + 1] == 's')
		hsab += ft_putstr(va_arg(argp, char *));
	else if (select[i] == '%' && select[i + 1] == 'p')
		hsab += ft_ahex(va_arg(argp, void *), 0);
	else if (select[i] == '%' && select[i + 1] == 'd')
		hsab += ft_putnbr(va_arg(argp, int), 0);
	else if (select[i] == '%' && select[i + 1] == 'i')
		hsab += ft_putnbr(va_arg(argp, int), 0);
	else if (select[i] == '%' && select[i + 1] == 'u')
		hsab += ft_putun(va_arg(argp, unsigned int), 0);
	else if (select[i] == '%' && select[i + 1] == 'x')
		hsab += ft_puthex(va_arg(argp, unsigned int), "0123456789abcdef", 0);
	else if (select[i] == '%' && select[i + 1] == 'X')
		hsab += ft_puthex(va_arg(argp, unsigned int), "0123456789ABCDEF", 0);
	else if (select[i] == '%' && select[i + 1] == '%')
		hsab += ft_putchar('%');
	return (hsab);
}

int	ft_printf(const char *select, ...)
{
	va_list	args;
	int		i;
	int		hsab;

	va_start(args, select);
	i = 0;
	hsab = 0;
	while (select[i])
	{
		if (select[i] == '%')
		{
			hsab += action(select, args, i);
			i++;
		}
		else
			hsab += ft_putchar(select[i]);
		i++;
	}
	va_end(args);
	return (hsab);
}
