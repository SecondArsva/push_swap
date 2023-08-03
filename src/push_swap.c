/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:41:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/04 00:37:13 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
*/
int	ft_sort(int argc, t_list **stack_a, t_list **stack_b)
{
	if (ft_two_values(argc, stack_a))
		return (ft_lstclear(stack_a, free), 0);
	if (ft_three_values(argc, stack_a))
		return (ft_lstclear(stack_a, free), 0);
	if (ft_four_values(argc, stack_a, stack_b))
		return (ft_lstclear(stack_a, free), 0);
	if (ft_five_values(argc, stack_a, stack_b))
		return (ft_lstclear(stack_a, free), 0);
	if (!ft_value_substitution(argc, stack_a))
		return (ft_lstclear(stack_a, free), 0);
	ft_radix(argc, stack_a, stack_b);
	return (1);
}

int	ft_args_validation(int argc, char **argv, t_list **stack_a)
{
	if (argc < 2)
		return (0);
	if (!ft_check_args_valid_chars(argv))
		return (0);
	if (ft_one_value(argc, argv))
		return (0);
	if (!ft_stack_create(stack_a, argc - 1, argv))
		return (ft_lstclear(stack_a, free), 0);
	if (!ft_check_args_int_range_and_dup(*stack_a))
		return (ft_lstclear(stack_a, free), 0);
	if (ft_ordered(*stack_a))
		return (ft_lstclear(stack_a, free), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	//atexit(ft_leaks);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_args_validation(argc, argv, &stack_a))
		return (0);
	if (!ft_sort(argc, &stack_a, &stack_b))
		return (0);
	return (ft_lstclear(&stack_a, free), 0);
}
