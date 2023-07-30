/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:27:29 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/30 12:04:50 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_five_values_moves(t_list **stack_a, t_list **stack_b, int pos)
{
	if (pos == 0)
		ft_pb(stack_b, stack_a);
	else if (pos == 1)
	{
		ft_sa(stack_a);
		ft_pb(stack_b, stack_a);
	}
	else if (pos == 2)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_pb(stack_b, stack_a);
	}
	else if (pos == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
	else if (pos == 4)
	{
		ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
}

int	ft_five_values(int argc, t_list **stack_a, t_list **stack_b)
{
	int	min_val_pos;

	min_val_pos = 0;
	if (argc == 6)
	{
		min_val_pos = ft_find_min_val_pos(*stack_a);
		ft_five_values_moves(stack_a, stack_b, min_val_pos);
		ft_four_values(argc - 1, stack_a, stack_b);
		ft_three_values(argc - 2, stack_a);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}
