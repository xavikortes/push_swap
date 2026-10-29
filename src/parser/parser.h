/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:55:41 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/15 14:47:46 by jcortes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

/* ENUM TO DEFINE STRATEGIES */
typedef enum e_strategy
{
	STRAT_NONE = -1,
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

/* STRUCT TO STORE CONFIG AND PARSED DATA */
typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
	int			*numbers;
	int			size;
}	t_config;

/* parser.c */
int		parsing_input(int ac, char **av, t_config *config, int allow_flags);

/* parser_utils.c */
void	free_config(t_config *config);
void	free_split(char **token);
int		validate_and_atol(const char *str, int *out);
int		has_duplicate(int *arr, int size, int val);

#endif
