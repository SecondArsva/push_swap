/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:41:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/21 08:03:47 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/push_swap.h"

int	ft_comp_args_valid_chars(char **m)
{
	t_iter i;

	i.i = 1;
	i.j = 0;
	while(m[i.i])
	{
		if(!ft_isdigit(m[i.i][i.j]) && (m[i.i][0] != '-' || m[i.i][1] == '\0'))
			return (ft_printf("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
		i.j++;
		while (m[i.i][i.j])
		{
			if(!ft_isdigit(m[i.i][i.j]))
				return (ft_printf("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return (ft_printf("[v] Argumentos válidos.\n"), 1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	if (!ft_comp_args_valid_chars(argv))
			return (0);
	return (0);
}
