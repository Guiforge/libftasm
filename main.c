/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:41:11 by gpouyat           #+#    #+#             */
/*   Updated: 2018/10/17 16:17:45 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./tests/test.h"
#include "./libfts.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	do_test_len(int nb)
{
	char *string;

	string = calloc(nb + 1, 1);
	memset(string, 't', nb);
	assert(strlen(string) == ft_strlen(string));
	free(string);
}

static int		test_strlen()
{
	int count;

	count = 0;
	printf("\nft_strlen: ");

	while (count <= 450)
	{
		do_test_len(count);
		count++;
	}
	printf("√... [%d tests]\n", count);
	return (count);
}

static char *strings[322] = {
	"\0",
	"Montpellier, first mentioned in a document of 985, was founded under a local feudal dynasty, the Guilhem, who combined two hamlets and built a castle and walls around the united settlement. The two surviving towers of the city walls, the Tour des Pins and the Tour de la Babotte, were built later, around the year 1200.\0",
	"42 is the best\0",
	"hello\0",
	"Erat antea publicae dignitati ego dignitati eadem satis sententia hominis multa ille satis reprehendant magis cumulus cum hac hominis Rei quae dierum C reprehendant ego decrevi cumulus dierum ego quae idem publicae erat tot ad meum meum quot antea magis quot dignitatem sententia erat hominis tot causa meum ex C antea eadem maxime causa Rei hac gratulatio quot decrevi decrevi in non hac mea tot Mario quot mea sententia maximis maxime hac hominis Rei Ergo dierum non ad est homines dis cum Rei erat cumulus necessitatem necessitatem in Ergo quae eadem tot ego ille dierum ex.\0",
	NULL
} ;

static int		test_strdup()
{
	int		count;
	char *points[2];

	printf("\nft_strdup: ");
	count = 0;
	while (strings[count])
	{
		points[0] = strdup(strings[count]);
		points[1] = ft_strdup(strings[count]);
		assert(!strcmp(points[0], points[1]));
		count++;
		free(points[0]);
		free(points[1]);
	}


	printf("√... [%d tests]\n", count);
	return(count);
}

//https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1473

static int				test_strncpy(void)
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

static int				test_strcpy(void)
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

static int test_strcat() {
	int		test_nb;
	char	buf[9];

	test_nb = 0;
	printf("\nft_strcat: ");
	bzero(buf, 9);
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");
	assert(strcmp(buf, "Bonjour.") == 0);
	assert(buf == ft_strcat(buf, ""));
	test_nb += 5;
	printf("√... [%d tests]\n", test_nb);
	puts("salut");
	return (test_nb);
}

static int	test_puts() {
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

/*
** https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1822
*/
static int		test_memset()
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

// https://github.com/QuentinPerez/Maintest/blob/master/libft/main.c#L1714

static int		test_memcpy()
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

static int		test_memalloc()
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

// static int			test_cat(void)
// {
// 	int		fd;

// 	puts("\nft_cat: ");
// 	fd = open("./main.c", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("ERROR");
// 		return(0);
// 	}
// 	ft_cat(fd);
// 	close(fd);
// 	// ft_cat(STDIN_FILENO);
// 	ft_cat(-1);
// 	puts("√... [2 tests]\n");	
// 	return(2);
// }

static void		do_test_bz(char *string_test, char *string, int count) {
	ft_bzero(string_test, count);
	bzero(string, count);
	assert(!memcmp(string_test, string, 40));
}

static int		test_bzero() {
	char string_test[40];
	char string[40];
	int		count;

	count = 0;
	printf("\nft_bzero: ");
	memset(string_test, 't', 40);
	memset(string, 't', 40);

	while (count <= 40) {
		do_test_bz(string_test, string, count);
		count++;
	}
	printf("√... [%d tests]\n", count);
	return (count);
}

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

void		main_test(void)
{
	size_t		test_nb;

	test_nb = 0;
	printf("#### start tests ####\n");

	test_nb += test_ascii("ft_isalpha", ft_isalpha, isalpha);	
	test_nb += test_ascii("ft_isdigit", ft_isdigit, isdigit);
	test_nb += test_ascii("ft_isalnum", ft_isalnum, isalnum);
	test_nb += test_ascii("ft_isascii", ft_isascii, isascii);
	test_nb += test_ascii("ft_isprint", ft_isprint, isprint);
	test_nb += test_ascii("ft_toupper", ft_toupper, toupper);
	test_nb += test_ascii("ft_tolower", ft_tolower, tolower);
	test_nb += test_bzero();
	test_nb += test_puts();
	test_nb += test_strlen();
	test_nb += test_strcat();
	test_nb += test_memset();
	test_nb += test_memcpy();
	test_nb += test_memalloc();
	test_nb += test_strdup();
	test_nb += test_strcpy();
	test_nb += test_strncpy();
	// test_nb += test_cat();
	// ft_cat(1);

	printf("\n ---- Total %zu tests passed ---- \n\n", test_nb);
}

int main() {
	main_test();
	return (0);
}
