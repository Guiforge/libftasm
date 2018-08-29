/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:47:35 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/29 18:27:07 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		test_memalloc()
{
	int		count;
	char	*tmp;
	char	*tmp1;

	count = 0;
	printf("\nft_memalloc: ");
	while (count <= 3000)
	{
		tmp = ft_memalloc(count);
		tmp1 = calloc(count, 1);
		if (tmp && tmp1)
			assert(!memcmp(tmp, tmp1, count));
		free(tmp1);
		free(tmp);
		++count;

	}
	printf("√... [%d tests]\n", count);	
	return(count);
}