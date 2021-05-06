/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:50:37 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/06 16:30:49 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		is_specifier(int check)
{
	int	loop;
	
	if (check >= 256 || check < 0)
		return (0);
	loop = 0;
	while(loop < ft_strlen(TYPE))
	{
		if (check == TYPE[loop])
			return (loop + 1);
		loop++;
	}
	return (0);
}

int		is_flag(int check)
{
	if (check >= 256 || check < 0)
		return (0);
	if (check == '*' || check == '-' || check == '0')
		return (1);
	else if (check == '.')
		return (2);
	return (0);
}

int		input_check(int check)
{
	if (check >= 256 || check < 0)
		return (0);
	if (is_flag(check) || ft_isdigit(check) || is_specifier(check))
		return (1);
	else
		return (0);
}