/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_substitution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:36:42 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 22:09:58 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_relative_num_pos(t_list **stack_a)
{
	long	min_val;
	int		node_pos;
	t_list	*tmp;

	min_val = LONG_MAX;
	node_pos = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (*(long *)tmp->content <= min_val
			&& *(long *)tmp->content >= INT_MIN)
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
	return (node_pos);
}

void	ft_set_relative_num(int argc, t_list **stack_a, long *arr)
{
	t_iter	i;
	int		min_val_pos;
	t_list	*aux;

	i.i = 0;
	i.li = 0;
	aux = *stack_a;
	while (i.i < argc -1)
	{
		min_val_pos = ft_find_relative_num_pos(stack_a);
		arr[min_val_pos] = i.li;
		i.li++;
		i.i++;
	}
	i.i = 0;
	while (aux)
	{
		*(long *)aux->content = arr[i.i];
		aux = aux->next;
		i.i++;
	}
}

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
	long	*arr;

	arr = ft_calloc(argc - 1, sizeof(long));
	if (!arr)
		return (ft_printf_error("Error\n"), 0);
	ft_think_in_positive(stack_a);
	ft_set_relative_num(argc, stack_a, arr);
	return (free(arr), 1);
}
