/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:41:19 by davidga2          #+#    #+#             */
/*   Updated: 2023/07/26 08:42:26 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/push_swap.h"
// usa macros para guardar el valor del max int y el min int
/*
int	ft_int_range(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MAX)
}
*/
int	ft_check_args_dup(t_list *stack)
{
	t_list	*current;
	t_list	*checked;

	current = stack;
	checked = current->next;
	ft_printf("---check_dup---\n");
	ft_printf("0\n");
	while (current->next)
	{
		ft_printf("current->content: %i | checked->content: %i\n", *(int *)current->content, *(int *)checked->content);
		if (*(int *)current->content == *(int *)checked->content)
			return (ft_printf_error("[x] No puede haber valores repetidos.\n"), 0);
		else if (checked->next)
			checked = checked->next;
		else
		{
			current = current->next;
			if (current->next)
				checked = current->next;
		}
	}
	ft_printf("---check_dup---\n");
	return (ft_printf("[v] Los todos los valores introducidos son diferentes.\n"), 1);
}

int	ft_stack_create(t_list **stack, int nodes, char **argv)
{
	t_iter	i;
	t_list	*tmp;
	int		*num;

	ft_printf("---ft_stack_create---\n");
	i.i = 1;
	num = NULL;
	ft_printf("[num] NULL:	%p\n", num);
	*stack = ft_lstcreate(nodes);
	tmp = *stack;
	ft_lstprint_str(*stack, "stack_a");
	while (i.i <= nodes)
	{
		ft_printf("[ft] argv[%i]: %s\n", i.i, argv[i.i]);
		num = ft_calloc(1, sizeof(int));
		if (!num)
			return (0);
		ft_printf("[num] calloc:	%p\n", num);
		*num = ft_atoi(argv[i.i]);
		ft_printf("[num] value: %i\n", *num);
		tmp->content = num;
		ft_printf("content: %i\n", *(int *)tmp->content);
		tmp = tmp->next;
		i.i++;
	}
	ft_lstprint_int(*stack, "stack_a");
	ft_printf("---ft_stack_create---\n");
	return (1);
}
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

int	ft_check_args_valid_chars(char **m)
{
	t_iter i;

	i.i = 1;
	i.j = 0;
	while(m[i.i])
	{
		if(!ft_isdigit(m[i.i][i.j]) && (m[i.i][0] != '-' || m[i.i][1] == '\0'))
			return (ft_printf_error("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
		i.j++;
		while (m[i.i][i.j])
		{
			if(!ft_isdigit(m[i.i][i.j]))
				return (ft_printf_error("[x] Caracter inválido: %c\n", m[i.i][i.j]), 0);
			i.j++;
		}
		i.j = 0;
		i.i++;
	}
	return (ft_printf("[v] Argumentos válidos.\n"), 1);
}

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	atexit(ft_leaks);
	stack_a = NULL;
	stack_b = NULL;
	int		i;

	i = 1;
	ft_printf("argc = %i\n", argc);
	if (argc < 2)
		return (ft_printf_error("[x] No se han introducido suficientes argumentos.\n"), 0);
	if (argc == 2)
	{
		return (ft_printf("[v] No se puede ordenar nada si solo hay un número.\n"), 0);
	}
	while (i < argc)
	{
		ft_printf("argv[%i]: %s\n", i, argv[i]);
		i++;
	}
	if (!ft_check_args_valid_chars(argv))
			return (0);
	if (!ft_stack_create(&stack_a, argc - 1, argv))
		return (ft_lstclear(&stack_a, free), 0);
	if (!ft_check_args_dup(stack_a))
		return (ft_lstclear(&stack_a, free), 0);
	ft_lstprint_int(stack_a, "stack_a");
	return (ft_lstclear(&stack_a, free), 0);
}
