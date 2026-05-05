/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:18:58 by roandres          #+#    #+#             */
/*   Updated: 2026/05/05 13:00:48 by roandres         ###   ########.fr       */
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
	a = parse_and_fill_stack(argc, argv, ctx.start_idx, &ctx);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	if (ctx.fn)
	{
		ft_putnbr_fd(a->value, 1);
		ft_putstr("\n");
	}
	b = NULL;
	set_node_index(a);
	if (ctx.bench)
		ctx.b.disorder = compute_disorder(a);
	if (!stack_sorted(a))
		run_strategy(&a, &b, &ctx);
	if (ctx.bench)
		print_bench(&ctx);
	free_stack(a);
	return (0);
}
