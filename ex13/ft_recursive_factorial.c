/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:39:10 by florian           #+#    #+#             */
/*   Updated: 2018/11/06 07:41:42 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int value;

	value = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (value * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>
int main()
{
	int x = ft_recursive_factorial(5);
	printf("%d", x);
}
