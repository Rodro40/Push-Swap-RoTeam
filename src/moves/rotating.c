/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:36 by roandres          #+#    #+#             */
/*   Updated: 2026/04/16 20:15:28 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_node(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **stack_a, int testing)
{
	ft_rotate_node(stack_a);
	if (!testing)
		ft_putstr("ra\n");
}

void	rb(t_stack_node **stack_b, int testing)
{
	ft_rotate_node(stack_b);
	if (!testing)
		ft_putstr("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int testing)
{
	ft_rotate_node(stack_a);
	ft_rotate_node(stack_b);
	if (!testing)
		ft_putstr("rr\n");
}
