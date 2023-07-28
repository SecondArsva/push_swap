/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:12:59 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/28 19:49:33 by davidga2         ###   ########.fr       */
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
