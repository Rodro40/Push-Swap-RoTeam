/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:18:58 by roandres          #+#    #+#             */
/*   Updated: 2026/03/31 17:47:52 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_strat(char *arg, t_strategy *strat)
{
	if (!ft_strncmp(arg, "--simple", 9))
		*strat = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		*strat = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		*strat = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		*strat = ADAPTIVE;
	else
		return (0);
	return (1);
}

// Parses flags, prevents duplicates, and catches invalid "--" flags.
int	parse_flags(char **argv, t_strategy *strat, int *bench, int *idx)
{
	int	s_set;

	s_set = 0;
	while (argv[*idx])
	{
		if (!ft_strncmp(argv[*idx], "--bench", 8))
			*bench = 1;
		else if (check_strat(argv[*idx], strat))
		{
			if (s_set)
				return (0);
			s_set = 1;
		}
		else if (!ft_strncmp(argv[*idx], "--", 2))
			return (0);
		else
			break ;
		(*idx)++;
	}
	return (1);
}

// Checks if stack is completely sorted
int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_strategy		strategy;
	int				bench;
	int				start_idx;
	float			disorder;

	if (argc < 2)
		return (0);
	strategy = ADAPTIVE;
	bench = 0;
	start_idx = 1;
	if (!parse_flags(argv, &strategy, &bench, &start_idx))
		return (write(2, "Error\n", 6), 1);
	if (start_idx >= argc)
		return (0);
	stack_a = parse_and_fill_stack(argc, argv, start_idx);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	set_node_index(stack_a);
	disorder = compute_disorder(stack_a);
	if (!is_sorted(stack_a))
	{
		// TODO: Llamaremos a los algoritmos aquí
	}
	return (free_stack(stack_a), 0);
}
