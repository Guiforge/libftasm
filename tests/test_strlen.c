/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 22:15:33 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/24 14:05:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	do_test(int nb)
{
	char *string;

	string = calloc(nb + 1, 1);
	memset(string, 't', nb);
	assert(strlen(string) == ft_strlen(string));
	free(string);
}

int		test_strlen()
{
	int count;

	count = 0;
	printf("\nft_strlen: ");

	while (count <= 450)
	{
		do_test(count);
		count++;
	}
	printf("√... [%d tests]\n", count);
	return (count);
}