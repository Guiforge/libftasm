/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:33:39 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/30 12:44:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1473

int				test_strncpy(void)
{
	char		ctab[11], ctab2[21], ctab3[21];
	int			i, j;
	size_t		k;
	int			count;

	printf("\nft_strncpy: ");
	k = 0;
	count = 0;
	while (k < 21)
	{
		i = 0;
		while (i < 502)
		{
			j = 0;
			while (j < 21)
			{
				if (j < 11)
					ctab[j] = ((char)rand() % 26) + 'a';
				ctab2[j] = 'Z';
				ctab3[j] = 'Z';
				j++;
			}
			ctab[10] = 0;
			ctab2[20] = 0;
			ctab3[20] = 0;
			assert (!(strncpy(ctab2, ctab, k) != ctab2 || ft_strncpy(ctab3, ctab, k) != ctab3));
			assert(!strcmp(ctab2, ctab3));
			count += 2;
			++i;
		}
		k++;
	}
	printf("√... [%d tests]\n", count);
	return (count);
}

int				test_strcpy(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};


	char			ctab[11], ctab2[11], ctab3[11];
	int				i, j;
	size_t			k;
	int				count;

	k = 0;
	count = 0;
	printf("\nft_strcpy: ");
	while (k <= sizeof(ctab))
	{
		i = 0;
		while (i < 502)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				j++;
			}
			ctab[10] = 0;
			assert(!(strcpy(ctab2, ctab) != ctab2 || ft_strcpy(ctab3, ctab) != ctab3));
			assert(!strcmp(ctab2, ctab3));
			count += 2;
			++i;
		}
		k++;
	}
	assert(strcpy(dest, "Hello foo") == ft_strcpy(dest, "Hello foo"));
	strcpy(dest, "Hello foo");
	ft_strcpy(dest2, "Hello foo");
	assert(!strcmp(dest, dest2));
	strcpy(dest, "Hello");
	ft_strcpy(dest2, "Hello");
	assert(!strcmp(dest, dest2));
	count += 3;
	printf("√... [%d tests]\n", count);
	return (count);
}