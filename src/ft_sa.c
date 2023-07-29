/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:09:54 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/29 20:36:35 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_sa(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	if (!tmp->next)
		(*lst)->next = NULL;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
	ft_printf("sa\n");
}
/*
int	main(void)
{
	int	switch_bool = 0;

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
	ft_swap(&a);
	ft_lstprint_str(a, "Complete list:");
	return (0);
}*/
