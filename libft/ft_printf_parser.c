/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:32:01 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:15 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	parse_flags(char **fmt, t_flags *flags)
{
	while (**fmt && (**fmt == '-' || **fmt == '0' || **fmt == '#'
			|| **fmt == '+' || **fmt == ' '))
	{
		if (**fmt == '-')
			flags->minus = 1;
		else if (**fmt == '0')
			flags->zero = 1;
		else if (**fmt == '#')
			flags->hash = 1;
		else if (**fmt == '+')
			flags->plus = 1;
		else if (**fmt == ' ')
			flags->space = 1;
		(*fmt)++;
	}
}

static int	parse_width(char **fmt)
{
	int	width;

	width = 0;
	while (**fmt && (**fmt >= '0' && **fmt <= '9'))
	{
		width = (width * 10) + (**fmt - '0');
		(*fmt)++;
	}
	return (width);
}

static int	parse_precision(char **fmt, t_flags *flags)
{
	int	prec;

	prec = 0;
	if (**fmt == '.')
	{
		flags->dot = 1;
		(*fmt)++;
		while (**fmt && (**fmt >= '0' && **fmt <= '9'))
		{
			prec = (prec * 10) + (**fmt - '0');
			(*fmt)++;
		}
	}
	return (prec);
}

void	parser(char **fmt, t_flags *flags)
{
	ft_bzero(flags, sizeof(t_flags));
	parse_flags(fmt, flags);
	flags->width = parse_width(fmt);
	flags->precision = parse_precision(fmt, flags);
	flags->specifier = **fmt;
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
}
