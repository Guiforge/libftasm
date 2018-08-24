/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:05:09 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/21 12:07:39 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_strcat() {
	int		test_nb;
	char	buf[9];

	test_nb = 0;
	printf("\nft_strcat: ");
	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	assert(strcmp(buf, "Bonjour.") == 0);
	assert(buf == ft_strcat(buf, ""));
	test_nb += 2;
	printf("√√\n");
	return (test_nb);
}