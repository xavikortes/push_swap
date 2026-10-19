/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:01:34 by jcortes           #+#    #+#             */
/*   Updated: 2026/10/19 14:00:33 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZER_H
# define ANALYZER_H

# include "../../libft/libft.h"
# include "../parser/parser.h"

typedef struct s_analysis
{
	int			disorder;
	const char	*strategy_name;
	const char	*complexity;
}	t_analysis;

int	get_disorder(const int *numbers, int size);
int	analyze_input(t_config *config, t_analysis *analysis);

#endif
