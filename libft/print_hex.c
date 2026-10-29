/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 02:01:49 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:29 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_hex_len(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	put_hex_rec(unsigned long n, const char *base)
{
	if (n >= 16)
		put_hex_rec(n / 16, base);
	ft_putchar_ret(base[n % 16], 1);
}

static int	print_hex_prefix(int uppercase, t_flags *flags, unsigned int n)
{
	if (flags->hash && n != 0)
	{
		if (uppercase)
			return (write(1, "0X", 2));
		return (write(1, "0x", 2));
	}
	return (0);
}

static int	get_hex_zeros(unsigned int n, int len, t_flags *flags)
{
	int	hash_sp;

	hash_sp = (flags->hash && n != 0) * 2;
	if (flags->dot && flags->precision > len)
		return (flags->precision - len);
	if (flags->zero && !flags->dot && flags->width > len + hash_sp)
		return (flags->width - (len + hash_sp));
	return (0);
}

int	print_hex(unsigned int n, int uppercase, t_flags *flags)
{
	int		cnt;
	int		len;
	int		z;
	int		sp;

	len = get_hex_len(n);
	if (flags->dot && flags->precision == 0 && n == 0)
		len = 0;
	z = get_hex_zeros(n, len, flags);
	sp = flags->width - (len + z + ((flags->hash && n != 0) * 2));
	cnt = 0;
	if (!flags->minus && (!flags->zero || flags->dot))
		cnt += print_padding(' ', sp);
	cnt += print_hex_prefix(uppercase, flags, n);
	cnt += print_padding('0', z);
	if (len > 0 && uppercase)
		put_hex_rec(n, "0123456789ABCDEF");
	else if (len > 0)
		put_hex_rec(n, "0123456789abcdef");
	if (flags->minus)
		cnt += print_padding(' ', sp);
	return (cnt + len);
}
