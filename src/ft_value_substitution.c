/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_substitution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:36:42 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 15:50:11 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This funtion find the min value, modify the content and return
// the node position. To the array idex identifier for radix.
int	ft_find_min_val_pos_val_subs(t_list **stack_a)
{
	long	min_val;
	int		node_pos;
	t_list	*tmp;

	min_val = *(long *)(*stack_a)->content;
	node_pos = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (*(long *)tmp->content < min_val && *(long *)tmp->content >= INT_MIN)
			min_val = *(long *)tmp->content;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp && *(long *)tmp->content != min_val)
	{
		node_pos++;
		tmp = tmp->next;
	}
	*(long *)tmp->content = INTMIN - 1;
	ft_printf("[FMVP] Node position: %i\n", node_pos);
	ft_lstprint_long(tmp, "stack_a subs");
	return (node_pos);
}

// This function modify the real values for relative values to optimize the
// sorting with radix. Navega toda la lista de forma similar al que busca si
// números repetidos modificando los valores del menor al mayor.

void	ft_think_in_positive(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	while (aux)
	{
		*(long *)aux->content = *(long *)aux->content + 2147483648;
		aux = aux->next;
	}
}

int	ft_value_substitution(int argc, t_list **stack_a)
{
	t_iter	i;
	int		min_val_pos;
	long	*arr;
	t_list	*aux;

	aux = *stack_a;
	i.i = 0;
	i.li = 0;
	arr = ft_calloc(argc - 1, sizeof(long));
	if (!arr)
		return (ft_printf_error("[x] No se ha reservado memoria correctamente.\n"), 0);
	ft_lstprint_long(*stack_a, "[TIP] pre:");
	sleep(2);
	ft_think_in_positive(stack_a);
	ft_lstprint_long(*stack_a, "[TIP] post:");
	sleep(2);
	while (i.i < argc -1)
	{
		ft_printf("i.i: %i| i.li: %i\n", i.i, i.li);
		min_val_pos = ft_find_min_val_pos_val_subs(stack_a);
		arr[min_val_pos] = i.li;
		i.li++;
		i.i++;
	}
	i.i = 0;
	ft_printf("[0]: %i, ptr: %p\n", arr[0], arr[0]);
	ft_printf("[1]: %i, ptr: %p\n", arr[1], arr[1]);
	ft_printf("[2]: %i, ptr: %p\n", arr[2], arr[2]);
	ft_printf("[3]: %i, ptr: %p\n", arr[3], arr[3]);
	ft_printf("[4]: %i, ptr: %p\n", arr[4], arr[4]);
	ft_printf("[5]: %i, ptr: %p\n", arr[5], arr[5]);
	while (aux)
	{
		//ft_lstprint_long(*stack_a, "[subs] stack_a");
		ft_printf("00\n");
		ft_lstprint_long(aux, "[subs] aux");
		*(long *)aux->content = arr[i.i];
		ft_printf("11\n");
		aux = aux->next;
		ft_printf("22\n");
		i.i++;
	}
	return (free(arr), 1);
}
