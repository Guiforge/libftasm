/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:52:21 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/29 18:57:05 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


int			test_cat(void)
{
	int		fd;

	puts("\nft_cat: ");
	fd = open("./main.c", O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR");
		return(0);
	}
	ft_cat(fd);
	close(fd);
	ft_cat(STDIN_FILENO);
	ft_cat(-1);
	puts("√... [2 tests]\n");	
	return(2);
}