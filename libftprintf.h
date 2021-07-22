/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavon <pavon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:45 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/07/21 18:21:02 by pavon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define TYPES "cspdiuxX%"
# define EXTRA ".0*-"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_printfStruct
{
	int	zero;
	int	width;
	int precision;
	int less;
	int haveSpace;
	int haveFlag;
}	t_printf;
int		ft_travel(va_list ap, const char *str);
int		ft_printf(const char *str, ...);


#endif


