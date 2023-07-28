/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:55:58 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/28 20:47:55 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
// Reverse Rotate A. "From the pit, to the pinacle." Papa Davidga II.
// Move all the nodes of a list to below,
// and the last node past to be the fist, the new head. Then, the next to last
// be the new last.
void	ft_rra(t_list **lst_a)
{
	t_list	*last_node;
	t_list	*next_to_last_node;
	int		i;
	int		next_to_last;

	last_node = NULL;
	next_to_last_node = NULL;
	i = 0;
	next_to_last = 0;
	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	last_node = ft_lstlast(*lst_a);
	next_to_last_node = *lst_a;
	next_to_last = ft_lstsize(*lst_a) - 2;
	while (i < next_to_last)
	{
		next_to_last_node = next_to_last_node->next;
		i++;
	}
	next_to_last_node->next = NULL;
	last_node->next = *lst_a;
	*lst_a = last_node;
	ft_printf("rra\n");
}
/*
int	main(void)
{
	t_list	*lst_a;
	
	lst_a = NULL;
	lst_a = ft_lstcreate(4);
	ft_printf("[LS] List size: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
//	ft_rra(NULL);
	ft_rra(&lst_a);
	ft_printf("Heil.\n");
	ft_printf("[LS] List size: %i\n", ft_lstsize(lst_a));
	ft_printf("Marvin.\n");
	ft_lstprint_str(lst_a, "lst_a");
	return (0);
}*/
