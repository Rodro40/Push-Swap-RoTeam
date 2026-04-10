/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigoa <rodrigoa@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:21:31 by rodrigoa          #+#    #+#             */
/*   Updated: 2026/04/10 14:12:50 by rodrigoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	heapify(int arr[], int n, int i)
{
	int	largest;
	int	left;
	int	right;
	int	temp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

void	heap_sort(int arr[], int n)
{
	int	i;
	int	temp;

	while (i >= 0)
	{
		i = n / 2 - 1;
		heapify(arr, n, i);
		i--;
	}
	while (i > 0)
	{
		i = n - 1;
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
		i--;
	}
}

int	main()
{
	int	arr[];
	int	n;

	arr[] = {9, 4, 3, 8, 10, 2, 5};
	n = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, n);
	while (i < n)
	{
		i = 0;
		printf("%d ", arr[i]);
	}
	return (0);
}
