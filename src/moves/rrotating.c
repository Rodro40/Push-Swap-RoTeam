/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:30 by roandres          #+#    #+#             */
/*   Updated: 2026/04/16 20:15:33 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate_node(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **stack_a, int testing)
{
	ft_rev_rotate_node(stack_a);
	if (!testing)
		ft_putstr("rra\n");
}

void	rrb(t_stack_node **stack_b, int testing)
{
	ft_rev_rotate_node(stack_b);
	if (!testing)
		ft_putstr("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int testing)
{
	ft_rev_rotate_node(stack_a);
	ft_rev_rotate_node(stack_b);
	if (!testing)
		ft_putstr("rrr\n");
}
