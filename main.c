/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:41:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/28 15:30:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_ascii(char *name, int (*ft_f)(int), int (*f)(int)) {
	int car;
	int test_nb;

	test_nb = 0;
	printf("\n%s: ", name);
	car = -400;
	while(car <= 400) {
		assert(ft_f(car) == f(car));
		test_nb++;
		car++;
	}
	printf("√... [%d tests]\n", test_nb);
	return (test_nb);
}

int main() {
	size_t		test_nb;

	test_nb = 0;
	printf("#### start tests ####\n");
	test_nb += test_bzero();
	test_nb += test_puts();
	test_nb += test_strlen();
	test_nb += test_ascii("ft_isalpha", ft_isalpha, isalpha);	
	test_nb += test_ascii("ft_isdigit", ft_isdigit, isdigit);
	test_nb += test_ascii("ft_isalnum", ft_isalnum, isalnum);
	test_nb += test_ascii("ft_isascii", ft_isascii, isascii);
	test_nb += test_ascii("ft_isprint", ft_isprint, isprint);
	test_nb += test_ascii("ft_toupper", ft_toupper, toupper);
	test_nb += test_ascii("ft_tolower", ft_tolower, tolower);
	test_nb += test_strcat();
	test_nb += test_memset();
	test_nb += test_memcpy();
	test_nb += test_strdup();

	printf("\n ---- Total %zu tests passed ---- \n\n", test_nb);

}