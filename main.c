/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:41:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/16 11:34:21 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests/test.h"

char	*ft_strcat2(char *dest, const char *src)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!dest || !src)
		return (NULL);
	i = strlen(dest);
	while (src[a])
	{
		dest[a + i] = src[a];
		a = a + 1;
	}
	dest[a + i] = '\0';
	return (dest);
}

int main() {
	main_test();
}