/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:41:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/21 10:27:11 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/push_swap.h"

void ft_stack_create(t_list **stack, int nodes, char **argv)
{
	t_iter	i;
	t_list	*tmp;
	int		*num;

	i.i = 1;
	num = NULL;
	ft_printf("[num] NULL:	%p\n", num);
	*stack = ft_lstcreate(nodes);
	tmp = *stack;
	ft_lstprint_str(*stack, "stack a");
	while (i.i <= nodes)
	{
		ft_printf("[ft] argv[%i]: %s\n", i.i, argv[i.i]);
		num = ft_calloc(1, sizeof(int));
		ft_printf("[num] calloc:	%p\n", num);
		*num = ft_atoi(argv[i.i]);
		ft_printf("[num] value: %i\n", *num);
		tmp->content = num;
		ft_printf("content: %i\n", *(int *)tmp->content);
		tmp = tmp->next;
		i.i++;
		ft_printf("[num] post-free: %p\n", num);
	}
	ft_lstprint_int(*stack, "stack a");
} // No sé qué cojones pasa que no libera num y se quedan todos los nodos con el
//		mismo valor.
//	Vale, no hace falta liberar en cada ciclo la memoria de num ya que como queda
//	almacenadaa en el content de cada nodo, si luego quisiéramos liberarlo habría
//	que liberar el contenido de los nodos. Si libero la memoria de num en cada
//	ciclo del bucle, al final solo existe un num con un valor, habiendo borrado
//	los antiguos punteros y haciendo que los contenidos de la lista tengan el
//	mismo valor ya que apuntan al mismo puntero, el num creado al final.
//	He de gestionar el hipotético caso en el que el que al hacer una nueva reserva
//	de memoria la reserva falle y por ende deba gestionar la liberación de toda
//	la lisla al no haber recibido correctamente los valores. Como lo de la
//	liberación de la matriz del split cuando iba mal.

int	ft_comp_args_valid_chars(char **m)
{
	t_iter i;

	i.i = 1;
	i.j = 0;
	while(m[i.i])
	{
		if(!ft_isdigit(m[i.i][i.j]) && (m[i.i][0] != '-' || m[i.i][1] == '\0'))
			return (ft_printf("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
		i.j++;
		while (m[i.i][i.j])
		{
			if(!ft_isdigit(m[i.i][i.j]))
				return (ft_printf("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return (ft_printf("[v] Argumentos válidos.\n"), 1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int		i;

	i = 1;
	ft_printf("argc = %i\n", argc);
	if (argc < 2)
		return (ft_printf("[x] No se han introducido suficientes argumentos"), 0);
	while (i < argc)
	{
		ft_printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	if (!ft_comp_args_valid_chars(argv))
			return (0);
	ft_stack_create(&a, argc - 1, argv);
	ft_lstprint_int(a, "a");
	return (0);
}
