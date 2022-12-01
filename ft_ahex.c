/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:56:22 by agimi             #+#    #+#             */
/*   Updated: 2022/10/26 11:57:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ahex(void *a, int hsab)
{
	size_t			ad;
	static size_t	hsab1;

	hsab1 = hsab;
	ad = (size_t) a;
	hsab1 = write(1, "0x", 2);
	hsab1 += ft_puthex(ad, "0123456789abcdef", hsab1);
	return (hsab1 - 2);
}
