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
#include <stdio.h>

void	heapify(int arr[], int n, int i)
{
	int	root;
	int	left;
	int	right;
	int	temp;

	root = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && arr[left] > arr[root])
		root = left;
	if (right < n && arr[right] > arr[root])
		root = right;
	if (root != i)
	{
		temp = arr[i];
		arr[i] = arr[root];
		arr[root] = temp;
		heapify(arr, n, root);
	}
}

void	heap_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	temp;

	i = (n / 2) - 1;
	while (i >= 0)
	{
		heapify(arr, n, i);
		i--;
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
int	params(int *arr)
{
	int	n;
	int	i;

	i = 0;
	n = (sizeof(arr) / sizeof(arr[i]));
	heap_sort(arr, n);
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}
