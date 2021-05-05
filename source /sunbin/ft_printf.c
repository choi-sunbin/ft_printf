/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:58:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/05 16:51:49 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
		result = proc_analysis_format(ap,(char*)format);
	va_end(ap);
}

int proc_analysis_format(va_list ap, char* format);
{
	int len;

	ft_strchr()
}

char* parsing_format(char* format, int* len)
{
	char	*ret_format;

	if (format[0] == '%')
		ret_format = proc_field_format(format, &len);
	else
		ret_format = proc_word_print(format, &len);
}
char* proc_field_format(char* format)