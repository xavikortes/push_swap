/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 01:41:10 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/15 02:27:35 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

# include "../analyzer/analyzer.h"
# include "../../libft/libft.h"

typedef enum e_operation
{
	noop = -1,
	sa = 0,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_operation;

typedef struct s_bench
{
	int	ops[11];
	int	total_ops;
}	t_bench;

void	bench_init(t_bench *bench);
void	bench_record(t_bench *bench, t_operation op);
void	print_benchmark(const t_analysis *analysis, const t_bench *bench);

#endif