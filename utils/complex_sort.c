/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigoa <rodrigoa@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:21:31 by rodrigoa          #+#    #+#             */
/*   Updated: 2026/04/23 13:40:51 by rodrigoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

static void	heapify(t_stack_node **arr, int n, int i)
{
	int	root;
	int	left;
	int	right;
	t_stack_node	*temp;

	root = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && arr[left]->value > arr[root]->value)
		root = left;
	if (right < n && arr[right]->value > arr[root]->value)
		root = right;
	if (root != i)
	{
		temp = arr[i];
		arr[i] = arr[root];
		arr[root] = temp;
		heapify(arr, n, root);
	}
}

void	heap_sort(t_stack_node **arr, int n)
{
	int	index;
	int	j;
	t_stack_node	*temp;

	index = (n / 2) - 1;
	while (index >= 0)
	{
		heapify(arr, n, index);
		index--;
	}
	j = n - 1;
	while (j >= 0)
	{
		temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;
		heapify(arr, j, 0);
		j--;
	}
}

// TESTING
void	complex_sort(t_stack_node **a, t_stack_node **b)
{
	int	n;
	int	index;
	int	bit;
	int	max_bits;
	t_stack_node	*current;
	t_stack_node	**nodes;

	(void)b;
	if (!a || !*a)
		return ;
	n = len_stack(*a);
	if (n <= 1)
		return ;
	nodes = malloc(n * sizeof(*nodes));
	if (!nodes)
		return ;
	current = *a;
	index = 0;
	while (current && index < n)
	{
		nodes[index++] = current;
		current = current->next;
	}
	heap_sort(nodes, n);
	index = 0;
	while (index < n)
	{
		nodes[index]->index = index;
		index++;
	}
	free(nodes);
	max_bits = 0;
	while ((n - 1) >> max_bits > 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		index = 0;
		while (index < n)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, 0);
			else
				pb(a, b, 0);
			index++;
		}
		while (*b)
			pa(a, b, 0);
		bit++;
	}
}
