/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:12:59 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/29 06:12:07 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_two_values(int argc, t_list **stack_a)
{
	if (argc == 3)
	{
		if (*(long *)(*stack_a)->content > *(long *)(*stack_a)->next->content)
			ft_rra(stack_a);
		return (1);
	}
	return (0);
}

int	ft_three_values(int argc, t_list **stack_a)
{
	t_content	c;

	if (argc == 4)
	{
		c.n0 = *(long *)(*stack_a)->content;
		c.n1 = *(long *)(*stack_a)->next->content;
		c.n2 = *(long *)(*stack_a)->next->next->content;
		if (c.n0 < c.n1 && c.n1 < c.n2 && c.n2 > c.n0)
			return (1);
		else if (c.n0 < c.n1 && c.n1 > c.n2 && c.n2 > c.n0)
			return (ft_rra(stack_a), ft_swap(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 < c.n2 && c.n2 > c.n0)
			return (ft_swap(stack_a), 1);
		else if (c.n0 < c.n1 && c.n1 > c.n2 && c.n2 < c.n0)
			return (ft_rra(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 < c.n2 && c.n2 < c.n0)
			return (ft_rra(stack_a), ft_rra(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 > c.n2 && c.n2 < c.n0)
			return (ft_swap(stack_a), ft_rra(stack_a), 1);
	}
	return (0);
}
