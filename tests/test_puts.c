/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:23:28 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/21 12:06:46 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_puts() {
	int	test_nb;
	int fd_back;

	fd_back = dup(STDOUT_FILENO);
	test_nb = 0;
	printf("\nft_puts: ");
	assert(ft_puts("- test ft_puts") == puts("- test puts"));
	test_nb++;
	printf("√");
	close(STDOUT_FILENO);
	assert(ft_puts("- test ft_puts") == puts("- test puts"));
	dup2(fd_back, STDOUT_FILENO);
	close(fd_back);
	test_nb++;
	printf("√");
	assert(puts(NULL) == ft_puts(NULL));
	test_nb++;
	ft_puts("√");
	return (test_nb);
}