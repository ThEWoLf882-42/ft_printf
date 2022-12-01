/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:00:55 by agimi             #+#    #+#             */
/*   Updated: 2022/10/26 11:48:55 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int hsab)
{
	static int	hsab1;

	hsab1 = hsab;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		hsab1 += ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		hsab1 += ft_putchar(n + 48);
	}	
	if (n > 9)
	{
		ft_putnbr(n / 10, hsab1);
		ft_putnbr(n % 10, hsab1);
	}
	return (hsab1);
}
