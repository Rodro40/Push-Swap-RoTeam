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

static void    set_used_strategy(t_ctx *ctx, t_strategy strat)
{
    if (ctx && ctx->bench)
        ctx->b.used_strategy = strat;
}

static void    run_low_disorder(t_stack_node **a, t_stack_node **b, t_ctx *ctx)
{
    int    ok;

    set_used_strategy(ctx, LINEAR);
    ok = linear_sort(a);
    if (!ok)
    {
        set_used_strategy(ctx, MEDIUM);
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
        set_used_strategy(ctx, MEDIUM);
        medium_sort(a, b);
    }
    else
    {
        set_used_strategy(ctx, COMPLEX);
        complex_sort(a, b);
    }
}

void    run_strategy(t_stack_node **a, t_stack_node **b, t_ctx *ctx)
{
    if (ctx->strategy == SIMPLE)
    {
        set_used_strategy(ctx, SIMPLE);
        simple_sort(a, b);
    }
    else if (ctx->strategy == MEDIUM)
    {
        set_used_strategy(ctx, MEDIUM);
        medium_sort(a, b);
    }
    else if (ctx->strategy == COMPLEX)
    {
        set_used_strategy(ctx, COMPLEX);
        complex_sort(a, b);
    }
    else
        run_adaptive(a, b, ctx);
}
