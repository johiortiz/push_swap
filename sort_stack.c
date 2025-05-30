/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:37:54 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/30 20:02:01 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	// 1. Obtener información básica
	// lo primero es saber cuántos núeros tenemos en la pila A.
	int	stack_size;
	
	stack_size = ft_get_stack_size(*a);	// Usas tu función para contar los nodos.
	
	// 2. Casos triviales o ya resueltos
	// Si la pila tiene 0 o 1 elemento, ya que está "ordenada", no hay nada que hacer.
	// También, si al revisar la pila A, resulta que ya está ordenada, tampco hacemos nada.
	if (stack_size <= 1 || ft_is_sorted(*a))
		return ;	// Salimos de la función, trabajo terminado.
	// 3. Decidir qué algoritmo usar según el tamaño
	// Ahora vienen las decisiones basadas en el tamaño_pila_a.
	// Si hay 2 números en la pila A:
	else if (stack_size == 2)
	{
		// Solo hay dos números. ¿Cuántos necesita un 'sa'?
		// Compara el valor del de arriba con el de abajo)
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	// Si hay 3 números en la pila A:
	else if (stack_size == 3)
		ft_sort_three(a);
	// Si hay 4 números en la pila A:
	else if (stack_size == 4)
		ft_sort_four(a, b);
	// Si hay 5 números en la pila A:
	else if (stack_size == 5)
		ft_sort_five(a, b);
	// Si hay 6 números en la pila A:
	else if (stack_size == 6)
		ft_sort_six(a, b);
	else
	{
		ft_sort_groups(a, b);
		ft_sort_back(a, b);
	}
}