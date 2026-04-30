/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:56:03 by roandres          #+#    #+#             */
/*   Updated: 2026/04/27 19:28:53 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void    set_bench_strategy(t_ctx *ctx, t_strategy mode, t_strategy comp)
{
    if (ctx && ctx->bench)
    {
        ctx->b.used_strategy = mode;
        ctx->b.used_complexity = comp;
    }
}

static void    run_low_disorder(t_stack_node **a, t_stack_node **b, t_ctx *ctx)
{
    int    ok;

    set_bench_strategy(ctx, ADAPTIVE, LINEAR);
    ok = linear_sort(a);
    if (!ok)
    {
        set_bench_strategy(ctx, ADAPTIVE, MEDIUM);
        medium_sort(a, b);
    }
}

static void    run_adaptive(t_stack_node **a, t_stack_node **b, t_ctx *ctx)
{
    float    disorder;

    disorder = compute_disorder(*a);
    if (disorder < 0.2f)
        run_low_disorder(a, b, ctx);
    else if (disorder < 0.5f)
    {
        set_bench_strategy(ctx, ADAPTIVE, MEDIUM);
        medium_sort(a, b);
    }
    else
    {
        set_bench_strategy(ctx, ADAPTIVE, COMPLEX);
        complex_sort(a, b);
    }
}

void    run_strategy(t_stack_node **a, t_stack_node **b, t_ctx *ctx)
{
    if (ctx->strategy == SIMPLE)
    {
        set_bench_strategy(ctx, SIMPLE, SIMPLE);
        simple_sort(a, b);
    }
    else if (ctx->strategy == MEDIUM)
    {
        set_bench_strategy(ctx, MEDIUM, MEDIUM);
        medium_sort(a, b);
    }
    else if (ctx->strategy == COMPLEX)
    {
        set_bench_strategy(ctx, COMPLEX, COMPLEX);
        complex_sort(a, b);
    }
    else
        run_adaptive(a, b, ctx);
}