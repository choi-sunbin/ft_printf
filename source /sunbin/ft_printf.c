/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:58:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/05 20:13:03 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		result;
	char	*temp;

	va_start(ap, format);
	temp = ft_strdup(format);
	result = proc_analysis_format(ap, temp);
	va_end(ap);
	return (1);
}

int		proc_analysis_format(va_list ap, char* format)
{
	int result;
	
	format = parsing_format(format, &result);
	return (1);
}

char	*parsing_format(char* format, int* ret)
{
	char	*ret_format;
	int		check_loop;

	while (format[0] != 0)
	{
		printf("check_loop [", ++check_loop);
		if (format[0] == '%')
			format = proc_field_format(format, ret);
		else
			format = proc_word_print(format, ret);
		printf("]\n");
	}
	return (ret_format);
}

char* proc_field_format(char* format, int *len)
{
	int loop;
	
	loop = 0;
	return (format);
}

char* proc_word_print(char *format, int *ret)
{
	char	*check_point;
	int		len;

	check_point = ft_strchr(format, '%');
	if (check_point != 0)
	{
		len = check_point - format;
		ret += len;
	}
	else
	{
		len = ft_strlen(format);
		ret += len;
	}
	write(1, format, len);
	return (format + len);
}

int		is_TYPE(int check)
{
	int	loop;
	
	loop = 0;
	while(loop < ft_strlen(TYPE))
	{
		if (check == TYPE[loop])
			return (loop + 1);
		loop++;
	}
	return (0);
}