/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:21:53 by gpouyat           #+#    #+#             */
/*   Updated: 2018/08/28 15:37:04 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <string.h>

void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_puts(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_memalloc(size_t len);
char				*ft_strcpy(char *dest, const char *src);

#endif
