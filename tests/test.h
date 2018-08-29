/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 21:52:44 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/29 19:04:40 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

#include "../libfts.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		test_bzero(void);
int		test_strlen(void);
int		test_puts(void);
int		test_strcat(void);
int		test_memset(void);
int		test_memcpy(void);
int		test_strdup(void);
int		test_cat(void);
int		test_memalloc(void);

#endif