/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:19:48 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 18:23:06 by davidga2         ###   ########.fr       */
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
	while (max_val != 0)
	{
		max_val = max_val >> 1;
		total_digits++;
	}
	return (total_digits);
}

void	ft_radix(int argc, t_list **stack_a, t_list **stack_b)
{
	t_iter	i;
	int		n_comp;

	i.i = 0;
	i.j = 0;
	n_comp = ft_max_val_binary_digits(*stack_a);
	while (!ft_ordered(*stack_a))
	{
		while (i.j < n_comp && !ft_ordered(*stack_a))
		{
			while (i.i < (argc - 1) && !ft_ordered(*stack_a))
			{
				if (((*(long *)(*stack_a)->content >> i.j) & 1))
					ft_ra(stack_a);
				else if (!((*(long *)(*stack_a)->content >> i.j) & 1))
					ft_pb(stack_b, stack_a);
				i.i++;
			}
			while (*stack_b)
				ft_pa(stack_a, stack_b);
			i.j++;
			i.i = 0;
		}
	}
}
