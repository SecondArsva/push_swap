/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:02:33 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/31 02:03:16 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*new_head;
	t_list	*last_node;

	tmp = NULL;
	new_head = NULL;
	last_node = NULL;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	new_head = (*stack_a)->next;
	last_node = ft_lstlast(*stack_a);
	last_node->next = tmp;
	tmp->next = NULL;
	*stack_a = new_head;
	ft_printf("ra\n");
}
/*
int	main(void)
{
	int	switch_bool = 1;

	t_list	*a = ft_lstnew(ft_strdup("UNO"));
	ft_lstprint_str(a, "a simple:");
	t_list	*b = ft_lstnew(ft_strdup("DOS"));
	ft_lstprint_str(b, "b simple:");
	t_list	*c = ft_lstnew(ft_strdup("TRES"));
	ft_lstprint_str(c, "c simple:");
	ft_lstadd_back(&a, b);
	if (switch_bool == 1)
		ft_lstadd_back(&a, c);
	ft_printf("\n");
	ft_lstprint_str(a, "Complete list:");
	ft_printf("\n");
	ft_ra(&a);
	ft_lstprint_str(a, "Complete list:");
	return (0);
}*/
