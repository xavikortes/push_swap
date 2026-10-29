/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:29:45 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:06 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *format, ...)
{
	int		printed;
	va_list	args;

	if (!format)
		return (-1);
	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			printed += print_arg(args, (char **)&format);
		}
		else
			printed += ft_putchar_ret(*format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (printed);
}
