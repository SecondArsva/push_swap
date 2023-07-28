/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:07:46 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/28 18:35:36 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMIN -2147483648
# define INTMAX 2147483647

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
int		ft_check_args_valid_chars(char **m);
int		ft_one_value(int argc, char **argv);
int		ft_one_value_int_range(const char *str);
int		ft_stack_create(t_list **stack, int nodes, char **argv);
int		ft_check_args_int_range_and_dup(t_list *stack);
int		ft_two_values(int argc, t_list **stack_a);
#endif
