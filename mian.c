/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:27:35 by aghlimi           #+#    #+#             */
/*   Updated: 2025/02/08 11:27:36 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc(size_t size, char flag, void *ptr)
{
	static t_gc	*gc_head = NULL;
	t_gc		*node;

	if (flag == 'm')
	{
		node = gc_alloc(size);
		if (node == NULL)
			return (NULL);
		add_gc(&gc_head, node);
	}
	else if (flag == 'f')
	{
		gc_clean(gc_head);
	}
	else if (flag == 'o')
	{
		gc_free(&gc_head, ptr);
	}
}
