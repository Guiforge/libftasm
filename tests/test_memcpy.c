/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:03:32 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/24 15:32:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1714

int		test_memcpy()
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2, *temp3;
	int				count;

	printf("\nft_memcpy: ");

	k = 0;
	count = 0;
	ft_memcpy(NULL, NULL, 42);
	ft_memcpy("42", NULL, 0);
	memcpy(NULL, NULL, 42);
	memcpy("42", NULL, 0);
	count += 2;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < 512)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * 1000;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			
			assert(!(memcmp(itab2, itab3, sizeof(itab)) != 0));
			assert((temp2 == itab3));
			assert(!(memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3));
			assert(!(memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3)));
			count += 3;
			++i;
		}
		++k;
	}
	printf("√... [%d tests]\n", count);	
	return (count);
}