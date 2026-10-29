/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 01:41:05 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/15 02:30:33 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

/* Reset benchmark operation counters */
void	bench_init(t_bench *bench)
{
	if (!bench)
		return ;
	ft_bzero(bench->ops, sizeof(bench->ops));
	bench->total_ops = 0;
}

/* Record an operation and update metrics */
void	bench_record(t_bench *bench, t_operation op)
{
	if (!bench)
		return ;
	if (op >= sa && op <= rrr)
	{
		bench->ops[op]++;
		bench->total_ops++;
	}
}

/* Print label with integer value */
static void	print_label_int(const char *label, int val)
{
	ft_putstr_fd((char *)label, 2);
	ft_putnbr_fd(val, 2);
}

/* Print disorder metrics */
static void	print_disorder(int disorder)
{
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(disorder / 100, 2);
	ft_putchar_fd('.', 2);
	if ((disorder % 100) < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(disorder % 100, 2);
	ft_putstr_fd("%\n", 2);
}

/* Function to print bench in stderr */
void	print_benchmark(const t_analysis *analysis, const t_bench *bench)
{
	if (!analysis || !bench)
		return ;
	print_disorder(analysis->disorder);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putstr_fd((char *)analysis->strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)analysis->complexity, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(bench->ops[sa], 2);
	print_label_int("  sb:  ", bench->ops[sb]);
	print_label_int("  ss:  ", bench->ops[ss]);
	print_label_int("  pa:  ", bench->ops[pa]);
	print_label_int("  pb:  ", bench->ops[pb]);
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(bench->ops[ra], 2);
	print_label_int("  rb:  ", bench->ops[rb]);
	print_label_int("  rr:  ", bench->ops[rr]);
	print_label_int("  rra:  ", bench->ops[rra]);
	print_label_int("  rrb:  ", bench->ops[rrb]);
	print_label_int("  rrr:  ", bench->ops[rrr]);
	ft_putstr_fd("\n", 2);
}
