/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:58:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/06 16:37:35 by sunbchoi         ###   ########.fr       */
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

	ret_format = 0;
	check_loop = 0;
	while (format && format[0] != 0)
	{
		printf("check_loop [%d]\n", ++check_loop);
		if (format[0] == '%')
		{
			format = proc_field_format(format, ret);
			if(format == 0)
			{
				printf("ERROR[%s]\n", format);
				return (0);
			}
		}
		else
		{
			format = proc_word_print(format, ret);
		}
	}
	return (ret_format);
}

char* proc_field_format(char* format, int *len)
{
	int		loop;
	int		format_len;
	int		field_len;
	char	*field_str;

	loop = 1;
	format_len = ft_strlen(format);
	while (loop < format_len && format[loop] != 0)
	{
		if (input_check(format[loop]))
		{
			if (is_specifier(format[loop]) != 0)
			{
				field_len = loop + 1;
				field_str = (char*)ft_calloc(sizeof(char), field_len + 1);
				if (field_str == 0)
					return(0);
				ft_memcpy(field_str, format, field_len);
				printf("FIELD_STR=[%s] FIELD_LEN=[%d]\n", field_str, field_len);
				return (format + field_len);
			}
		}
		else
			return (0);
		loop++;
	}
	return (0);
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

