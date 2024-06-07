/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:32:23 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/29 16:39:18 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t s)
{
	void	*memptr;
	size_t	tot;
	size_t	max_size;

	max_size = 4611686014132420608;
	if (s && n && max_size / n < s)
		return ((void *)0);
	if (n == 0 || s == 0)
		return (ft_calloc(1, 1));
	tot = n * s;
	if (tot / n != s)
		return ((void *)0);
	memptr = (void *)malloc(tot);
	if (!memptr)
		return ((void *)0);
	ft_bzero(memptr, tot);
	return (memptr);
}
