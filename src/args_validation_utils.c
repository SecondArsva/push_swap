/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:13:53 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 22:17:01 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_one_value_int_range(const char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INTMIN || num > INTMAX)
		return (ft_printf_error("Error\n"), 0);
	return (1);
}

int	ft_check_args_int_range_and_dup(t_list *stack)
{
	t_list	*current;
	t_list	*checked;

	current = stack;
	checked = current->next;
	while (current->next)
	{
		if ((*(long *)current->content < INTMIN
				|| *(long *)current->content > INTMAX)
			|| (*(long *)checked->content < INTMIN
				|| *(long *)checked->content > INTMAX))
			return (ft_printf_error("Error\n"), 0);
		if (*(int *)current->content == *(int *)checked->content)
			return (ft_printf_error("Error\n"), 0);
		else if (checked->next)
			checked = checked->next;
		else
		{
			current = current->next;
			if (current->next)
				checked = current->next;
		}
	}
	return (1);
}

int	ft_stack_create(t_list **stack, int nodes, char **argv)
{
	t_iter	i;
	t_list	*tmp;
	long	*num;

	i.i = 1;
	num = NULL;
	*stack = ft_lstcreate(nodes);
	tmp = *stack;
	while (i.i <= nodes)
	{
		num = ft_calloc(1, sizeof(long));
		if (!num)
			return (0);
		*num = ft_atol(argv[i.i]);
		tmp->content = num;
		tmp = tmp->next;
		i.i++;
	}
	return (1);
}

int	ft_one_value(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_one_value_int_range(argv[1]))
			return (1);
		return (1);
	}
	return (0);
}

int	ft_check_args_valid_chars(char **m)
{
	t_iter	i;

	i.i = 1;
	i.j = 0;
	while (m[i.i])
	{
		if (!ft_isdigit(m[i.i][i.j]) && (m[i.i][0] != '-' || m[i.i][1] == '\0'))
			return (ft_printf_error("Error\n"), 0);
		i.j++;
		while (m[i.i][i.j])
		{
			if (!ft_isdigit(m[i.i][i.j]))
				return (ft_printf_error("Error\n"), 0);
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return (1);
}
