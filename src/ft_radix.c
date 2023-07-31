/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:19:48 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/31 17:58:41 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_max_val_binary_digits(t_list *lst)
{
	long	max_val;
	int		total_digits;
	t_list	*tmp;

	max_val = *(long *)lst->content;
	total_digits = 0;
	tmp = lst;
	while (tmp)
	{
		if (*(long *)tmp->content > max_val)
			max_val = *(long *)tmp->content;
		tmp = tmp->next;
	}
	ft_printf("max_val: %i\n", max_val);
	sleep(1);
	while (max_val != 0)
	{
		ft_printf("HOLA\n");
		max_val = max_val >> 1;
		total_digits++;
	}
	ft_printf("iBEY total_digits: %i\n", total_digits);
	sleep(2);
	return (total_digits);
}

void	ft_radix(int argc, t_list **stack_a, t_list **stack_b)
{
	t_iter	i;
	int		n_comp;

	i.i = 0;
	i.j = 0;
	n_comp = ft_max_val_binary_digits(*stack_a);
	ft_lstprint_long(*stack_a, "[RADIX] stack_a");
	while (!ft_ordered(*stack_a))
	{
		ft_printf("i: %i | j: %i | n_comp:%i\n", i.i, i.j, n_comp);
		while (i.j < n_comp && !ft_ordered(*stack_a))
		{
			ft_printf("i.j value: %i\n", i.j);
			while (i.i < (argc - 1) && !ft_ordered(*stack_a))
			{
				ft_printf("i.i value: %i\n", i.i);
				if (((*(long *)(*stack_a)->content >> i.j) & 1))
					ft_ra(stack_a);
				else if (!((*(long *)(*stack_a)->content >> i.j) & 1))
					ft_pb(stack_b, stack_a);
				i.i++;
			}
			while (*stack_b)
				ft_pa(stack_a, stack_b);
			ft_lstprint_long(*stack_a, "[RADIX] stack_a");
			ft_lstprint_str(*stack_b, "[RADIX] stack_b");
			i.j++;
			i.i = 0;
		}
	}
}
// Necesito sacar la puta función que me de cuantas cifras componen al mayor
// valor introducido para ejecutar el paso 1 durante n veces si o si. Ya que
// tal y como lo tengo me da un bucle infinito, porque nunca se ordena.
// Si tengo 6 números del 1 al 6, el binario máximo tiene 3 cifras, no 6,
// por ello no se ordena nunca.
