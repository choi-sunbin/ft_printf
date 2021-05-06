/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:59:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/06 20:41:24 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

# define TYPE "cspdiuxX%"
# define TYPE_CHARACTER_C 0
# define TYPE_STRING_S 1
# define TYPE_POINTER_P 2
# define TYPE_INT_D 3
# define TYPE_INT_I 4
# define TYPE_UNSIGNED_U 5
# define TYPE_HEX_LOW_X 6
# define TYPE_HEX_UP_X 7
# define TYPE_PERSENT 8

typedef struct print_info
{
    int flag_minus;
    int flag_zero;
    int width_len;
    int presicion_len;
    int seperator;
} tprint_info;

int		ft_printf(const char *format, ...);
int		proc_split_format(va_list ap, char* format);
char*   proc_field_format(char* format, int *len);
char*   proc_word_format(char *format, int *ret);

/*      INPUT_CHECK.c       */
int		is_specifier(int check);
int		is_flag(int check);
int		input_check(int check);


#endif