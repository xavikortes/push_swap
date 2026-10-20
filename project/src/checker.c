/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:58:09 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/19 13:10:35 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "stacker/stacker.h"
#include "analyzer/analyzer.h"

void	do_nothing(void *c)
{
	(void) c;
}

int	soft_exit(t_config *config, t_state *state, int *nums, int print_status)
{
	if (config)
		free_config(config);
	if (state)
		free_state(state, &do_nothing);
	if (nums)
		free(nums);
	if (print_status)
		ft_putendl_fd("Error", 2);
	return (1);
}

int	perform_operations(t_state *state)
{
	char		*line;
	t_operation	op;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		op = get_operation(line);
		free(line);
		if (op == -1)
			return (0);
		stack_operate(op, state);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			*nums;
	t_config	config;
	t_state		state;

	if (argc == 1)
		return (0);
	nums = NULL;
	ft_bzero(&state, sizeof(t_state));
	if (!parsing_input(argc, argv, &config, 0))
		return (soft_exit(&config, NULL, NULL, 1));
	fill_state(config.numbers, config.size, &state);
	if (!perform_operations(&state))
		return (soft_exit(&config, &state, nums, 1));
	if (state.b != NULL)
		return (ft_printf("KO\n"), soft_exit(&config, &state, nums, 0), 0);
	nums = export_state(&state);
	if (!nums)
		return (soft_exit(&config, &state, nums, 1));
	if (get_disorder(nums, config.size) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (soft_exit(&config, &state, nums, 0), 0);
}
