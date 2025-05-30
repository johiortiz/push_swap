/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:15:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/30 22:42:31 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calcula la raíz cuadrada entera 
// Ej: ft_sqrt(10) = 3 (porque 3*3=9; 4*4=16-> se pasa)
static int	ft_sqrt(int n)	// 'n' es el número del que queremos la raíz cuadrada
{
	int i;
	
	i = 0;
	// Mientras que 'i' multiplicada por sí misma (i*i) sea menor o igual que 'n'
	while ((i * i) <= n)
		i++;	// probamos con una iteración mas grande
	i--; //Cuando el bucle termina 'i*i' es MAYOR que 'n', significa que se pasó.
	return (i);
}

// Mueveve los números de la pila A a la pila B, en "paquetes" o "grupos" pequeños basándose en su index.
// La idea es que los números con index pequeños (que van primero en el orden final)
// se traten de una forma, y los que tienen index dentro de ciertos "rangos" se muevan a B también.
// Los números con index muy grandex (que van al final del orden) se suelen rotar en A para esperar su "turno". 
void	ft_sort_groups(t_stack **a t_stack **b, int n_arg)
{
	int	index_count;
	int	size;
	int	current_index;
	
	if (n_arg == 0 || !(*a))
		return ;
	index_count = 0;
	size = (ft_sqrt(n_arg) * 133 / 100);
	if (size == 0)
		size = n_arg;
	while (*a != NULL)
	{
		current_index = (*a)->index;
		if (current_index <= index_count)
		{
			pb(a, b);
			rb(b);
			index_count++;
		}
		else if (current_index <= index_count + size)
		{
			pb(a, b);
			index_count++;
		}
		else 
			ra(a);
	}
}

// Función para encontrar la posición del index más grande
// Mirará la pila que le pases (que será B en este contexto) y 
// te dirá en qué posición (0 para la cima, 1 para la siguiente, etc.)
// se encuentra el nodo que tiene el index más grande en ese momento.
static int	ft_biggest_index_pos(t_stack *stack)
{
	int	bigger_index;
	int	bigger_pos;
	int current_pos;
	t_stack	*current_node;

	if (!stack)
		return (-1);
	bigger_index = stack->index;
	bigger_pos = 0;
	current_pos = 0;
	current_node  = stack;
	while (current_node != NULL)
	{
		if (current_node->index > bigger_index)
		{
			// si entramos aqui, significa que el 'nodo_actual' que estamos
			// mirando AHORA tiene un 'index' MÄS GRANDE que cualquiera que 
			// hayamos visto ANTES en la pila.
			// 1. Actualizamos el 'indice_más_grande':
			// ahora, el nuevo 'record' de índice más gramde es el 'index' de este 'nodo_Actual'
			bigger_index = current_node->index;
			// 2. Actualizamos 'posición_del_más_grande':
			// También necesitamos recordar DÖNDE encontramos este nuevo índices 
			// más grande. La 'posición_actual' nos dice justo eso (en qué lugar de la pila
			// está el'nodo_actual').
			bigger_pos = current_pos;
		}
		// Despues de revisar el nodo actuall (y actualizar si fuera necesario),
		// nos preparamos para el siguiente:
		current_node = current_node->next;
		current_pos++;
	}
	return (bigger_pos);
}

// Esta función es la encargada de tomar todos los números que ft_sort_groups dejó en la pila
// B  pasarlos de vuelta a la pila A, pero de tal forma que la pila A quede perfectamente ordenada
// (con el index 0 arriba, luego el 1, y así hast N-1 abajo).
void	ft_sort_back(t_stack **a, t_stack **b)
{
	int	b_index_pos;
	int	b_current_size;
	int	rotations;
	int	rev_rotations;
	
	// Mientras que la pila B no esté vacía
	while (*b != NULL)
	{
		// 1. Averiguar dónde está el elemento con el 'index' más grande de la 'pila'
		b_index_pos = ft_biggest_index_pos(*b);
		// 2. Averiguar cuántos elementos hay en total en la pila B ahora mismo.
		b_current_size = ft_get_stack_size(*b);	// Es importante obtener el tamaño DESPUËS de asegurarte de que *b no es NULL
		// 3. Mover el nodo con el 'index' más grande a la cima de la pila B.
		// Si b_index_pos es -1, algo fue mal o la pila B se vació inesperadamente.
		// Pero el while(*b != NULL) debería prevenir esto si ft_biggest_index_pos
 		// siempre encuentra algo en una pila no vacía.
		if (b_index_pos > 0)
		{
			if (b_index_pos <= b_current_size / 2)
			{
				// Está en la primera mitaf (o justo en medio, si es más cercano por arriba).
				// Es más eficiente usar 'rb'.
				// ¿Cuántas veces? Si está en pos 0, 0 veces. Si está en pos 1, 1 en vez. etc.
				rotations = b_index_pos;
				while (rotations-- > 0)
					rb(b);
			}
			else
			{
				// Está en la segunda mitad. Es más eficiente usar 'rrb'.
				// ¿Cuántas veces? Si está en pos 3 y hay 4 elementos (0,1,2,3), size=4.
				// pos=3. (4-3)=1 rrb.
				rev_rotations = b_current_size - b_index_pos;
				while (rrbs_num-- > 0)
					rrb(b);
			}
		}
		// Ahora el elemento deseado está en la cima de B.
		pa(a,b);
	}
}