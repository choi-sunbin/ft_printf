/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:59:51 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/05/05 16:32:44 by sunbchoi         ###   ########.fr       */
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

int				ft_printf(const char *format, ...);

#endif