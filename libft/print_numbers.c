/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 00:33:22 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:33 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	put_num_rec(long n)
{
	if (n >= 10)
		put_num_rec(n / 10);
	ft_putchar_ret((n % 10) + '0', 1);
}

static int	print_sign(long *n, t_flags *flags)
{
	int	count;

	count = 0;
	if (*n < 0)
	{
		count += ft_putchar_ret('-', 1);
		*n = -*n;
	}
	else if (flags->plus)
		count += ft_putchar_ret('+', 1);
	else if (flags->space)
		count += ft_putchar_ret(' ', 1);
	return (count);
}

static int	get_zeros(long n, int len, t_flags *flags)
{
	int	prefix;

	prefix = (n < 0 || flags->plus || flags->space);
	if (flags->dot && flags->precision > len)
		return (flags->precision - len);
	if (flags->zero && !flags->dot && flags->width > len + prefix)
		return (flags->width - (len + prefix));
	return (0);
}

int	print_int(long n, t_flags *flags)
{
	int	count;
	int	len;
	int	zeros;
	int	spaces;

	count = 0;
	len = get_num_len(n);
	if (flags->dot && flags->precision == 0 && n == 0)
		len = 0;
	zeros = get_zeros(n, len, flags);
	spaces = flags->width - (len + zeros
			+ (n < 0 || flags->plus || flags->space));
	if (!flags->minus && (!flags->zero || flags->dot))
		count += print_padding(' ', spaces);
	count += print_sign(&n, flags);
	count += print_padding('0', zeros);
	if (len > 0)
		put_num_rec(n);
	if (flags->minus)
		count += print_padding(' ', spaces);
	return (count + len);
}
