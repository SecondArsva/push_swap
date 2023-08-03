/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:12:59 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 22:06:19 by davidga2         ###   ########.fr       */
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
			return (ft_rra(stack_a), ft_sa(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 < c.n2 && c.n2 > c.n0)
			return (ft_sa(stack_a), 1);
		else if (c.n0 < c.n1 && c.n1 > c.n2 && c.n2 < c.n0)
			return (ft_rra(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 < c.n2 && c.n2 < c.n0)
			return (ft_rra(stack_a), ft_rra(stack_a), 1);
		else if (c.n0 > c.n1 && c.n1 > c.n2 && c.n2 < c.n0)
			return (ft_sa(stack_a), ft_rra(stack_a), 1);
	}
	return (0);
}

int	ft_find_min_val_pos(t_list *lst)
{
	long	min_val;
	int		node_pos;
	t_list	*tmp;

	min_val = *(long *)lst->content;
	node_pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (*(long *)tmp->content < min_val)
			min_val = *(long *)tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		if (*(long *)tmp->content == min_val)
			return (node_pos);
		node_pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_four_values_moves(t_list **stack_a, t_list **stack_b, int pos)
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
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
	else if (pos == 3)
	{
		ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
}

int	ft_four_values(int argc, t_list **stack_a, t_list **stack_b)
{
	int	min_val_pos;

	min_val_pos = 0;
	if (argc == 5)
	{
		min_val_pos = ft_find_min_val_pos(*stack_a);
		ft_four_values_moves(stack_a, stack_b, min_val_pos);
		ft_three_values(argc - 1, stack_a);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}
