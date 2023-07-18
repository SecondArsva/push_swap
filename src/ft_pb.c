/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 04:18:04 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/18 05:27:29 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
// Push b. Push the first node of the list a to the top of the list b.
void	ft_pb(t_list **lst_b, t_list **lst_a)
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst_a || !*lst_a)
		return ;
	tmp = *lst_a;
	if (*lst_a)
		*lst_a = (*lst_a)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
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

	ft_printf("\n[-][-][-] PRE-SWAP B [-][-][-]\n");
	ft_printf("[LS] a: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
	ft_printf("[LS] b: %i\n", ft_lstsize(lst_b));
	ft_lstprint_str(lst_b, "lst_b");
	ft_printf("\n");

	ft_pb(&lst_b, &lst_a);

	ft_printf("\n[-][-][-] POST-SWAP B [-][-][-]\n");
	ft_printf("[LS] a: %i\n", ft_lstsize(lst_a));
	ft_lstprint_str(lst_a, "lst_a");
	ft_printf("[LS] b: %i\n", ft_lstsize(lst_b));
	ft_lstprint_str(lst_b, "lst_b");
	return (0);
}*/
