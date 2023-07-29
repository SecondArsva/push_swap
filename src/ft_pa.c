/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:26:09 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/29 20:32:03 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
// Push a. Push the first node of the list b to the top of the list a.
void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst_b || !*lst_b)
		return ;
	tmp = *lst_b;
	if (*lst_b)
		*lst_b = (*lst_b)->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	ft_printf("pa\n");
}
/*
int	main(void)
{
	t_list	*lst_a;
	t_list	*lst_b;
	
	lst_a = ft_lstcreate(2);
	lst_b = ft_lstcreate(2);
	
//	lst_a = ft_lstcreate(2);
//	lst_b = ft_lstcreate(0);

//	lst_a = ft_lstcreate(0);
//	lst_b = ft_lstcreate(2);

	ft_printf("\n[-][-][-] PRE-SWAP A [-][-][-]\n");
	ft_printf("[LS] a: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
	ft_printf("[LS] b: %i\n", ft_lstsize(lst_b));
	ft_lstprint_str(lst_b, "lst_b");
	ft_printf("\n");

	ft_pa(&lst_a, &lst_b);

	ft_printf("\n[-][-][-] POST-SWAP A [-][-][-]\n");
	ft_printf("[LS] a: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
	ft_printf("[LS] b: %i\n", ft_lstsize(lst_b));
	ft_lstprint_str(lst_b, "lst_b");
	return (0);
}*/
