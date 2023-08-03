/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 03:46:16 by davidga2          #+#    #+#             */
/*   Updated: 2023/08/03 22:05:09 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_ordered(t_list *lst)
{
	while (lst->next)
	{
		if (*(long *)lst->content > *(long *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
