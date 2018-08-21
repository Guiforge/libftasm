/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:41:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/21 12:05:28 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_ascii(char *name, int (*ft_f)(int), int (*f)(int)) {
	int car;
	int test_nb;

	test_nb = 0;
	printf("\n%s: ", name);
	car = -4;
	while(car <= 200) {
		assert(ft_f(car) == f(car));
		test_nb++;
		car++;
		printf("√");
	}
	printf("\n");
	return (test_nb);
}

// static int	test_puts() {
// 	int	test_nb;
// 	int fd_back;

// 	test_nb = 0;
// 	printf("---- test ft_puts ---- \n");


// 	assert(ft_puts("- test ft_puts") == puts("- test puts"));
// 	test_nb++;
// 	ft_puts("√");

// 	fd_back = dup(STDOUT_FILENO);
// 	close(STDOUT_FILENO);
// 	assert(ft_puts("- test ft_puts") == puts("- test puts"));
// 	dup2(fd_back, STDOUT_FILENO);
// 	close(fd_back);
// 	test_nb++;
// 	ft_puts("√");


// 	assert(puts(NULL) == ft_puts(NULL));
// 	test_nb++;
// 	ft_puts("√");

// 	printf("\n ---- %d tests passed ---- \n\n", test_nb);
// 	return (test_nb);
// }

// static int test_strcat() {
// 	int		test_nb;
// 	char	buf[9];

// 	test_nb = 0;
// 	printf("---- test ft_strcat ---- \n");


// 	bzero(buf, 9);
// 	ft_strcat(buf, "");
// 	ft_strcat(buf, "Bon");
// 	ft_strcat(buf, "j");
// 	ft_strcat(buf, "our.");
// 	ft_strcat(buf, "");
// 	assert(strcmp(buf, "Bonjour.") == 0);
// 	assert(buf == ft_strcat(buf, ""));
// 	test_nb++;
// 	ft_puts("√");

// 	printf("\n ---- %d tests passed ---- \n\n", test_nb);
// 	return (test_nb);
// }

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

	printf("\n ---- Total %zu tests passed ---- \n\n", test_nb);

}