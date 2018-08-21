/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:52:21 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/20 22:26:13 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


static void		do_test(char *string_test, char *string, int count) {
	ft_bzero(string_test, count);
	bzero(string, count);
	assert(!memcmp(string_test, string, 40));
}

int		test_bzero() {
	char string_test[40];
	char string[40];
	int		count;

	count = 0;
	printf("\nft_bzero: ");
	memset(string_test, 't', 40);
	memset(string, 't', 40);

	while (count <= 40) {
		do_test(string_test, string, count);
		count++;
		printf("√");
	}
	printf("\n");
	return (count);
}