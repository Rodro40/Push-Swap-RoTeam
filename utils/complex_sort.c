/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigoa <rodrigoa@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:21:31 by rodrigoa          #+#    #+#             */
/*   Updated: 2026/04/22 16:13:48 by rodrigoa         ###   ########.fr       */
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
	if (left < n && arr[left] > arr[i])
		largest = left;
	if (right < n && arr[right] > arr[i])
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
	int	j;
	int	temp;

	i = (n / 2);
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
int	main()
{
	int	arr[] = {7, 5, 9, 42, 0, 10, 3, 4};
	int	n;
	int	i;

	i = 0;
	n = (sizeof(arr) / sizeof(arr[i]));
	heap_sort(arr, n);
	printf("%d\n", n);
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}