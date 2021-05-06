/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filed_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:17:13 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/06 20:41:18 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     field_proc(char *field,  va_list ap)
{
	tprint_info	f_info;
	char		char_width[100];
	char		char_precision[100];
	int			loop;
	int			field_len;

    loop = 0;
	ft_bzero(&f_info, sizeof(f_info));
	ft_bzero(char_width, 100);
	ft_bzero(char_precision, 100);

	while (is_flag(field[0]) == '-' || is_flag(field[0]) == '0')
	{
		if(is_flag(field[0]) == '-')
			f_info.flag_minus = 1;
		else if(is_flag(field[0]) == '0')
			f_info.flag_zero = 1;
		field++;
	}
	while (ft_isdigit(field[0]))
		ft_strlcat(char_width, field++, ft_strlen(char_width) + 1 + 1);
	if(field[0] == '*')
	{
		if(ft_strlen(char_width) == 0)
			f_info.width_len = va_arg(ap, int);
		else
		{
			printf("WIDTH ERROR=[%s]",field);
			return (-1);
		}
	}	
}