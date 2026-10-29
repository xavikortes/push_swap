/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:03:16 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:26 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Putchar with return value */
int	ft_putchar_ret(char c, int fd)
{
	return (write(fd, &c, 1));
}

/* Complete size with spaces */
int	print_padding(char c, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_putchar_ret(c, 1);
		len--;
	}
	return (count);
}

/* Handle left or right alignment based on width and flags */
int	print_char(int c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus)
	{
		count += ft_putchar_ret((char)c, 1);
		count += print_padding(' ', flags->width - 1);
	}
	else
	{
		count += print_padding(' ', flags->width - 1);
		count += ft_putchar_ret((char)c, 1);
	}
	return (count);
}

int	print_str(const char *s, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (!s)
	{
		if (flags->dot && flags->precision < 6)
			s = "";
		else
			s = "(null)";
	}
	len = ft_strlen(s);
	if (flags->dot && flags->precision < len)
		len = flags->precision;
	if (flags->minus)
	{
		count += write(1, s, len);
		count += print_padding(' ', flags->width - len);
	}
	else
	{
		count += print_padding(' ', flags->width - len);
		count += write(1, s, len);
	}
	return (count);
}
