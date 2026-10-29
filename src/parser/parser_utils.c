/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:09:12 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/10 17:36:58 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->numbers)
	{
		free(config->numbers);
		config->numbers = NULL;
	}
	config->size = 0;
}

void	free_split(char **token)
{
	int	i;

	if (!token)
		return ;
	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}

int	validate_and_atol(const char *str, int *out)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
			return (0);
		str++;
	}
	*out = (int)(sign * num);
	return (1);
}

int	has_duplicate(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}
