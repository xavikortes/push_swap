/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernfern <fernfern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 02:18:06 by fernfern          #+#    #+#             */
/*   Updated: 2026/10/14 14:17:39 by fernfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(void *ptr, t_flags *flags)
{
	unsigned long	addr;
	int				cnt;
	int				len;
	int				sp;

	if (!ptr)
		return (print_str("(nil)", flags));
	addr = (unsigned long)ptr;
	len = get_hex_len(addr) + 2;
	sp = flags->width - len;
	cnt = 0;
	if (!flags->minus)
		cnt += print_padding(' ', sp);
	cnt += write(1, "0x", 2);
	put_hex_rec(addr, "0123456789abcdef");
	if (flags->minus)
		cnt += print_padding(' ', sp);
	return (cnt + len - 2);
}
