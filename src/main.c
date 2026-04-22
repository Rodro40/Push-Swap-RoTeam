/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:18:58 by roandres          #+#    #+#             */
/*   Updated: 2026/04/22 12:03:56 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_ctx			ctx;
	int				status;

	status = init_ctx(argc, argv, &ctx);
	if (status == 0)
		return (0);
	if (status < 0)
		return (write(2, "Error\n", 6), 1);
	a = parse_and_fill_stack(argc, argv, ctx.start_idx);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = NULL;
	set_node_index(a);
	if (!stack_sorted(a))
		run_strategy(&a, &b, &ctx);
	free_stack(a);
	return (0);
}
