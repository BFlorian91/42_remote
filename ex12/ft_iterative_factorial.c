/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:31:37 by florian           #+#    #+#             */
/*   Updated: 2018/11/06 07:37:42 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int value;

	value = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		value = value * (nb - 1);
		--nb;
	}
	return (value);
}

#include <stdio.h>
int		main()
{
	int x = ft_iterative_factorial(5);
	printf("%d", x);
}
