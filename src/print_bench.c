/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roandres <roandres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:20:35 by roandres          #+#    #+#             */
/*   Updated: 2026/04/29 15:22:18 by roandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void    put_two_digits(int n, int fd)
{
    char    c;

    c = '0' + (n / 10);
    write(fd, &c, 1);
    c = '0' + (n % 10);
    write(fd, &c, 1);
}

static void    print_disorder(t_ctx *ctx)
{
    int    scaled;
    int    whole;
    int    dec;

    scaled = (int)(ctx->b.disorder * 10000.0f + 0.5f);
    whole = scaled / 100;
    dec = scaled % 100;
    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd(whole, 2);
    write(2, ".", 1);
    put_two_digits(dec, 2);
    ft_putstr_fd("%\n", 2);
}

static void    print_complexity(t_ctx *ctx)
{
    if (ctx->b.used_complexity == LINEAR)
        ft_putstr_fd("O(n)", 2);
    else if (ctx->b.used_complexity == MEDIUM)
        ft_putstr_fd("O(n*sqrt(n))", 2);
    else if (ctx->b.used_complexity == COMPLEX)
        ft_putstr_fd("O(n*log(n))", 2);
    else if (ctx->b.used_complexity == SIMPLE)
        ft_putstr_fd("O(n^2)", 2);
    else
        ft_putstr_fd("O(?)", 2);
}

static void    print_strategy(t_ctx *ctx)
{
    ft_putstr_fd("[bench] strategy: ", 2);
    if (ctx->b.used_strategy == ADAPTIVE)
        ft_putstr_fd("Adaptive / ", 2);
    else if (ctx->b.used_strategy == SIMPLE)
        ft_putstr_fd("Simple / ", 2);
    else if (ctx->b.used_strategy == MEDIUM)
        ft_putstr_fd("Medium / ", 2);
    else if (ctx->b.used_strategy == COMPLEX)
        ft_putstr_fd("Complex / ", 2);
    else
        ft_putstr_fd("Unresolved / ", 2);
    print_complexity(ctx);
    ft_putstr_fd("\n", 2);
}

static void    print_counts(t_ctx *ctx)
{
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd((int)ctx->b.total, 2);
    ft_putstr_fd("\n[bench] sa: ", 2);
    ft_putnbr_fd((int)ctx->b.sa, 2);
    ft_putstr_fd(" sb: ", 2);
    ft_putnbr_fd((int)ctx->b.sb, 2);
    ft_putstr_fd(" ss: ", 2);
    ft_putnbr_fd((int)ctx->b.ss, 2);
    ft_putstr_fd(" pa: ", 2);
    ft_putnbr_fd((int)ctx->b.pa, 2);
    ft_putstr_fd(" pb: ", 2);
    ft_putnbr_fd((int)ctx->b.pb, 2);
    ft_putstr_fd("\n[bench] ra: ", 2);
    ft_putnbr_fd((int)ctx->b.ra, 2);
    ft_putstr_fd(" rb: ", 2);
    ft_putnbr_fd((int)ctx->b.rb, 2);
    ft_putstr_fd(" rr: ", 2);
    ft_putnbr_fd((int)ctx->b.rr, 2);
    ft_putstr_fd(" rra: ", 2);
    ft_putnbr_fd((int)ctx->b.rra, 2);
    ft_putstr_fd(" rrb: ", 2);
    ft_putnbr_fd((int)ctx->b.rrb, 2);
    ft_putstr_fd(" rrr: ", 2);
    ft_putnbr_fd((int)ctx->b.rrr, 2);
    ft_putstr_fd("\n", 2);
}

void    print_bench(t_ctx *ctx)
{
    if (!ctx || !ctx->bench)
        return ;
    print_disorder(ctx);
    print_strategy(ctx);
    print_counts(ctx);
}