/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:26:00 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/29 18:27:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
static char *strings[322] = {
	"\0",
	"Montpellier, first mentioned in a document of 985, was founded under a local feudal dynasty, the Guilhem, who combined two hamlets and built a castle and walls around the united settlement. The two surviving towers of the city walls, the Tour des Pins and the Tour de la Babotte, were built later, around the year 1200.\0",
	"42 is the best\0",
	"hello\0",
	"Erat antea publicae dignitati ego dignitati eadem satis sententia hominis multa ille satis reprehendant magis cumulus cum hac hominis Rei quae dierum C reprehendant ego decrevi cumulus dierum ego quae idem publicae erat tot ad meum meum quot antea magis quot dignitatem sententia erat hominis tot causa meum ex C antea eadem maxime causa Rei hac gratulatio quot decrevi decrevi in non hac mea tot Mario quot mea sententia maximis maxime hac hominis Rei Ergo dierum non ad est homines dis cum Rei erat cumulus necessitatem necessitatem in Ergo quae eadem tot ego ille dierum ex.\0",
	NULL
} ;

int		test_strdup()
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