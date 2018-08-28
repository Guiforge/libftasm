/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:26:00 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/28 15:32:32 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		test_strdup()
{
	int		count;
	char *points[2];

	printf("\nft_strdup: ");
	count = 0;
	points[0] = ft_strdup("");
	points[1] = strdup("");
	assert(!strcmp(points[0], points[1]));
	count++;
	free(points[0]);
	free(points[1]);

	points[0] = ft_strdup("42 is the best");
	points[1] = strdup("42 is the best");
	assert(!strcmp(points[0], points[1]));
	count++;
	free(points[0]);
	free(points[1]);
	printf("√... [%d tests]\n", count);
	return(count);
}