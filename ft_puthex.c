/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:03:30 by agimi             #+#    #+#             */
/*   Updated: 2022/10/30 12:03:30 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t a, char *c, int hsab)
{
	static int	hsab1;

	hsab1 = hsab;
	if (a >= 0 && a <= 15)
		hsab1 += ft_putchar(c[a % 16]);
	if (a > 15)
	{
		ft_puthex(a / 16, c, hsab1);
		ft_puthex(a % 16, c, hsab1);
	}
	return (hsab1);
}
