/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:24:36 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:22 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_conversor(char conv, va_list args, t_flags *flags)
{
	if (conv == '%')
		return (ft_putchar_ret('%', 1));
	if (conv == 'c')
		return (print_char(va_arg(args, int), flags));
	if (conv == 's')
		return (print_str(va_arg(args, const char *), flags));
	if (conv == 'p')
		return (print_ptr(va_arg(args, void *), flags));
	if (conv == 'd' || conv == 'i')
		return (print_int((long)va_arg(args, int), flags));
	if (conv == 'u')
	{
		flags->plus = 0;
		flags->space = 0;
		return (print_int((long)va_arg(args, unsigned int), flags));
	}
	if (conv == 'x')
		return (print_hex(va_arg(args, unsigned int), 0, flags));
	if (conv == 'X')
		return (print_hex(va_arg(args, unsigned int), 1, flags));
	return (0);
}

int	print_arg(va_list args, char **fmt)
{
	t_flags	flags;
	char	conv;

	parser(fmt, &flags);
	conv = **fmt;
	if (!conv)
		return (0);
	return (format_conversor(conv, args, &flags));
}
