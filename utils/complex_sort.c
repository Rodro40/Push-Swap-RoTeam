/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:21:31 by rodrigoa          #+#    #+#             */
/*   Updated: 2026/04/28 00:00:00 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	heapify(t_stack_node **arr, int n, int i)
{
	int				root;
	int				left;
	int				right;
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

static void	heap_sort(t_stack_node **arr, int n)
{
	int				index;
	int				j;
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

void	complex_sort(t_stack_node **a, t_stack_node **b)
{
	int				n;
	int				index;
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
}
