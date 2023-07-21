/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:07:46 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/21 09:01:13 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_iters{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
}			t_iter;

void	ft_pa(t_list **lst_a, t_list **lst_b);
void	ft_pb(t_list **lst_b, t_list **lst_a);
void	ft_rra(t_list **lst_a);
int		main(int argc, char *argv[]);
#endif
