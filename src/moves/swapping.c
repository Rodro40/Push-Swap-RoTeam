/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:20:18 by roandres          #+#    #+#             */
/*   Updated: 2026/04/16 20:15:39 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_nodes(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	sa(t_stack_node **stack_a, int testing)
{
	ft_swap_nodes(stack_a);
	if (!testing)
		ft_putstr("sa\n");
}

void	sb(t_stack_node **stack_b, int testing)
{
	ft_swap_nodes(stack_b);
	if (!testing)
		ft_putstr("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, int testing)
{
	ft_swap_nodes(stack_a);
	ft_swap_nodes(stack_b);
	if (!testing)
		ft_putstr("ss\n");
}
