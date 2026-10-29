/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:53:25 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/19 13:33:24 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyzer.h"

/* Count total inversions found in array */
static long	count_inversions(const int *nums, int size)
{
	long	inv;
	int		i;
	int		j;

	inv = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] > nums[j])
				inv++;
			j++;
		}
		i++;
	}
	return (inv);
}

/* Aux static function to choose final strategy */
static void	set_metadata(t_strategy og_strat, t_strategy res_strat,
			t_analysis *analysis)
{
	if (og_strat == STRAT_ADAPTIVE)
		analysis->strategy_name = "Adaptive";
	else if (res_strat == STRAT_SIMPLE)
		analysis->strategy_name = "Simple";
	else if (res_strat == STRAT_MEDIUM)
		analysis->strategy_name = "Medium";
	else
		analysis->strategy_name = "Complex";
	if (res_strat == STRAT_SIMPLE)
		analysis->complexity = "O(n^2)";
	else if (res_strat == STRAT_MEDIUM)
		analysis->complexity = "O(n√n)";
	else
		analysis->complexity = "O(nlogn)";
}

/* Calculates disorder scaled ratio (base 10000) */
int	get_disorder(const int *numbers, int size)
{
	long	total_pairs;
	long	inv;
	long	scaled;

	if (!numbers || size <= 1)
		return (0);
	total_pairs = ((long)size * (size - 1)) / 2;
	inv = count_inversions(numbers, size);
	scaled = ((inv * 10000) + (total_pairs / 2)) / total_pairs;
	return ((int)scaled);
}

/* Analyzes input disorder and resolves sorting strategy */
int	analyze_input(t_config *config, t_analysis *analysis)
{
	t_strategy	og_strat;

	if (!config || !analysis || config->numbers == NULL)
		return (0);
	og_strat = config->strategy;
	analysis->disorder = get_disorder(config->numbers, config->size);
	if (config->strategy == STRAT_ADAPTIVE)
	{
		if (analysis->disorder < 2000)
			config->strategy = STRAT_SIMPLE;
		else if (analysis->disorder < 5000)
			config->strategy = STRAT_MEDIUM;
		else
			config->strategy = STRAT_COMPLEX;
	}
	set_metadata(og_strat, config->strategy, analysis);
	return (1);
}
