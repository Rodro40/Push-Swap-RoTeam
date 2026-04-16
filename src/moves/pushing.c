/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:40 by roandres          #+#    #+#             */
/*   Updated: 2026/04/16 20:15:15 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **to, t_stack_node **from)
{
	t_stack_node	*to_push;

	if (!*from)
		return ;
	to_push = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	to_push->prev = NULL;
	if (!*to)
	{
		*to = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *to;
		(*to)->prev = to_push;
		*to = to_push;
	}
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b, int testing)
{
	push(stack_a, stack_b);
	if (!testing)
		ft_putstr("pa\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, int testing)
{
	push(stack_b, stack_a);
	if (!testing)
		ft_putstr("pb\n");
}
