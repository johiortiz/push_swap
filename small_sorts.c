/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:11:56 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/31 02:43:41 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_position_smallest_value(t_stack *stack_a)
{
	t_stack	*current_node = stack_a;
	int	min_value;
	int	min_pos;
	int	current_pos;

	if (!current_node)	// si la pila está vacía
		return (-1); 
	// Inicializamos el primer nodo
	min_value = current_node->value;
	min_pos = 0;
	current_pos = 0;
	// Recorre el resto de la pila
	while (current_node != NULL)
	{
		// ¿El valor del nodo actual es menor que el mínimo que teníamos?
		if (current_node->value < min_value)
		{
			// ¡Sí! Actualizamos
			min_value = current_node->value;
			min_pos = current_pos;
		}
		current_pos++;	// Avanzamos el contador de posición
		current_node = current_node->next; 	// Pasamos al siguiente nodo	
	}
	return (min_pos);
}

void	ft_sort_three(t_stack **a)	// 'a' es u puntero al puntero de la cima de la pila A
{
	int	x;
	int	y;
	int	z;
	
	if (!a || !*a || !(*a)->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	
	if (x > y && y < z && x < z)
		sa(a);	// (2,1,3->1,2,3)
	else if (x > y && y > z)
	{
		ra(a);	// (3,2,1->2,1,3)
		sa(a);	// (2,1,3->1,2,3)
	}
	else if (x > y && y < z && x > z)
		ra(a);	// (3,1,2->1,2,3)
	else if (x < y && y > z && x < z)
	{
		rra(a);	// (1,3,2->2,1,3)
		sa(a); // (2,1,3->1,2,3)
	}
	else if (x < y && y > z && x > z)
		rra(a);	// (2,3,1->1,2,3)
}


void	ft_sort_four(t_stack **a, t_stack **b)
{
	int current_size;
	int	smallest;

	current_size = ft_get_stack_size(*a);	// obtener el tamaño de la pila
	if (current_size != 4)	// si no tiene 4 elementos
		return ;	// esta función no para esta situación, salimos
	if (ft_is_sorted(*a))	// si ya está ordenada, no hay nada que hacer, salimos
		return ;
	smallest = ft_position_smallet_value(*a);
	if (smallest == 0)	// si el más pequeño está en la posición 0
		//  ya está no hya que hacer nada en este paso
	else if (smallest == 1)	// si el más pequeño está en la posición 1 (el segundo elemento)
		ra(a);
	else if (smallest == 2)
	{
		ra(a);
		ra(a);
	}
	else if (smallest == 3)	// en el fondo
		rra(a);	// una rotación inversa lo trae directamente a la cima
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	current_size;
	int	smallest;
	int	rot_num;
	int	rra_need;
	
	current_size = ft_get_stack_size(*a);
	if (current_size != 5)
		return ;
	if (ft_is_sorted(*a))
		return ;
	smallest = ft_get_position_smallest_value(*a);
	else if (smallest == 1 || smallest == 2)
	{
		rot_num = smallest;
		while (rot_num > 0)
		{
			ra(a);
			rot_num--;
		}
		else if (smallest == 3 || smallest == 4)
		{
			rra(a);
			rra_need--;
		}
		
	}
	pb(a, b);
	ft_sort_four(a, b);
	pa(a, b);
}

void	ft_sort_six(t_stack **a, t_stack **b)
{
	int current_size;
	int	smallest;
	int rot_num;
	int rra_need;
	
	current_size = ft_get_stack_size(*a);
	if (current_size != 6)
		return ;
	if (is_sorted(*a))
		return ;
	smallest = ft_position_smallet_value(*a);
	if (smallest == 0)
		// no hacemos nada
	else if (smallest >= 1 && smallest <= 3)
	{
		rot_num = smallest;
		while (rot_num > 0)
		{
			ra(a);
			rot_num--;
		}
	}
	else if (smallest >= 4 && smallest <= 5)
	{
		rra_need = 6 - smallest;
		while (rra_need > 0)
		{
			rra(a);
			rra_need--;
		}
	}
	pb(a, b);
	ft_sort_five(a, b);
	pa(a, b);
}
