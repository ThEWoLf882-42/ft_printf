/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:18:43 by agimi             #+#    #+#             */
/*   Updated: 2022/10/26 12:00:38 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int n, int hsab)
{
	static int	hsab1;

	hsab1 = hsab;
	if (n >= 0 && n <= 9)
	{
		hsab1 += ft_putchar(n + 48);
	}	
	if (n > 9)
	{
		ft_putun(n / 10, hsab1);
		ft_putun(n % 10, hsab1);
	}
	return (hsab1);
}
