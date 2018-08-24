/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:12:32 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/24 12:08:55 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
/*
** https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1822
*/
int		test_memset()
{

	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j, k;
	void			*temp, *temp2;
	int				count;

	printf("\nft_memset: ");

	// memset(NULL, 0, 0);
	// ft_memset(NULL, 0, 0);
	k = 0;
	count = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < 512)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				itab[j] = rand();
				ltab[j] = (unsigned long)rand() * 10000;
				j++;
			}
			memcpy(ctab2, ctab, sizeof(ctab));
			memcpy(itab2, itab, sizeof(itab));
			memcpy(ltab2, ltab, sizeof(ltab));
			temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
			assert(memcmp(itab, itab2, sizeof(itab)) == 0);
			assert(temp == itab);
			assert(temp2 == itab2);
			++count;
			temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			assert(!(memcmp(ctab, ctab2, sizeof(ctab)) != 0 || temp != ctab || temp2 != ctab2));
			++count;
			temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			assert(!(memcmp(ltab, ltab2, sizeof(ltab)) != 0 || temp != ltab || temp2 != ltab2));
			++count;
			++i;
		}
		++k;
	}
	printf("√... [%d tests]\n", count);
	return (count);
}