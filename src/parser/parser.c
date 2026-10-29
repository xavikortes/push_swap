/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:17:11 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/19 13:40:37 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_flag(const char *arg, t_config *config, int allow_flags)
{
	if (!allow_flags)
		return (0);
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (config->bench != 0)
			return (0);
		config->bench = 1;
		return (1);
	}
	if (config->strategy != STRAT_NONE)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	return (1);
}

/* Count number of elements */
static int	count_args(char *arg, t_config *config, int *count, int allow_flags)
{
	char	**tokens;
	int		i;
	int		val;

	if (arg[0] == '-' && arg[1] == '-')
		return (parse_flag(arg, config, allow_flags));
	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		return (free_split(tokens), 0);
	i = 0;
	while (tokens[i])
	{
		if (!validate_and_atol(tokens[i], &val))
			return (free_split(tokens), 0);
		(*count)++;
		i++;
	}
	free_split(tokens);
	return (1);
}

/* Fill preallocated array with validated numbers */
static int	fill_arg(char *arg, t_config *config)
{
	char	**tokens;
	int		i;
	int		val;

	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	i = 0;
	while (tokens[i])
	{
		validate_and_atol(tokens[i], &val);
		if (has_duplicate(config->numbers, config->size, val))
			return (free_split(tokens), 0);
		config->numbers[config->size++] = val;
		i++;
	}
	free_split(tokens);
	return (1);
}

/* Second loop to fill array and check duplicates */
static int	fill_all(int ac, char **av, t_config *config)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!fill_arg(av[i], config))
			return (free_config(config), 0);
		i++;
	}
	return (1);
}

int	parsing_input(int ac, char **av, t_config *config, int allow_flags)
{
	int	i;
	int	total;

	config->strategy = STRAT_NONE;
	config->bench = 0;
	config->numbers = NULL;
	config->size = 0;
	total = 0;
	i = 1;
	while (i < ac)
	{
		if (!count_args(av[i], config, &total, allow_flags))
			return (0);
		i++;
	}
	if (config->strategy == STRAT_NONE)
		config->strategy = STRAT_ADAPTIVE;
	if (total == 0)
		return (0);
	config->numbers = (int *)malloc(sizeof(int) * total);
	if (!config->numbers)
		return (0);
	return (fill_all(ac, av, config));
}
