/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:37:08 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/16 14:24:33 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "stacker/stacker.h"
#include "analyzer/analyzer.h"
#include "bench/bench.h"
#include "solver/solver.h"

/* Dummy deleter for ft_lstclear when nodes don't own their content */
static void	do_nothing(void *c)
{
	(void)c;
}

/* Main function */
int	main(int ac, char **av)
{
	t_config	config;
	t_analysis	analysis;
	t_state		state;
	t_bench		bench;

	if (ac < 2)
		return (0);
	if (!parsing_input(ac, av, &config, 1))
		return (write(2, "Error\n", 6), 1);
	if (!analyze_input(&config, &analysis))
		return (free_config(&config), write(2, "Error\n", 6), 1);
	if (analysis.disorder == 0)
		return (free_config(&config), 0);
	fill_state(config.numbers, config.size, &state);
	if (config.bench)
	{
		bench_init(&bench);
		state.bench = &bench;
	}
	solve_sorting(&state, &config);
	if (config.bench)
		print_benchmark(&analysis, &bench);
	free_state(&state, &do_nothing);
	free_config(&config);
	return (0);
}
