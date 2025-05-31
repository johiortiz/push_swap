/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:53:07 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/31 02:00:28 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value, int index_value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_exit_error(NULL, NULL);
	node->value = value;
	node->index = index_value;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_bottom(t_stack **stack_head, t_stack *node_to_add)
{
	if (!node_to_add)
		return;
	if (!*stack_head)
	{
		*stack_head = node_to_add;
		return;
	}
	t_stack *current = *stack_head;
	while (current->next != NULL)
		current = current->next;
	current->next = node_to_add;
}

void	ft_free_stack(t_stack **stack_head)
{
	t_stack	*current;
	t_stack	*next_node;

	if (stack_head == NULL || *stack_head == NULL)
		return ;

	current = *stack_head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack_head = NULL;
}

int	ft_get_stack_size(t_stack *head)
{
	int	count;
	t_stack *current;
	
	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

bool	ft_is_sorted(t_stack *stack_a_head)
{
	t_stack	*current;

	if (stack_a_head == NULL || stack_a_head->next == NULL)
		return (true);
	current = stack_a_head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	ft_assign_index(t_stack *stack_a)
{
	t_stack	*current_node;	// Para recorrer la pila
	int	size;				// Para guardar cuántos números hay
	int *arr;				// Para copiar y ordenar los números
	int	i;
	
	if (!stack_a)	// Si no hay pila, no hay nada que hacer
		return ;

	size = ft_get_stack_size(stack_a);	// Averiguamos cuántos números hay
	if (size == 0)		// Si la pila está cavía, tampoco hacemos nada
		return ;

	// Creamos el array con espacio para todos los números
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		ft_exit_error(NULL,NULL);
		return ;
	}
	// Copiamos los números de la pila al array
	current_node = stack_a;	// Empezamos por el primer nodo de la pila
	i = 0;					// Empezamos a llenar el array desde la posición 0
	while (i < size)		// Repetimos mientras que no hayamos copiado todos los números
	{
		arr[i] = current_node->value;	// Copiamos el valor del nodo actual
		current_node = current_node->next;	// Pasamos al sigueinte nodo de la pila
		i++;								// Pasamos a lla siguiente posición en 'arr'
	}
	// Ordenamos el array
	// Usamos un método simple llamado "Bubble Sort" 
	// Comprara pareja de números y las intercambia si no están en orden, repitiendo
	// hasta que toda la lista esté ordenada.
	
	i = 0;	// Contador para las pasadas
	while (i < size - 1) // Hay que hacer 'size - 1' pasadas
	{
		int j = 0;	// Contador para compara elementos dentro de una pasada
		while (j < size - i - 1)	// En cada pasada, el último 'i' elemento ya está ordenado
		{
			if (arr[j] > arr[j + 1]) // SI el actual es mayor que el siguiente
			{
				// los intercambia de lugar
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;	// Pasamos al siguiente par para comparar
		}
		i++;	//Siguiente pasada
	}
	// Asignamos los index a los nodos de la pila original
	current_node = stack_a;	// Volvemos al inicio de nuestra pila
	while (current_node != NULL)	// Mientras haya nodos en la pila
	{
		i = 0;	// Empezamos a buscar en el array desde ell principio
		while (i < size)	// Mientras que no haya recorrido el array desde el principio
		{
			if (current_node->value == arr[i])	// Si el valor del nodo de a pila es igual del array
			{
				current_node->index = i;	// la posición en el array es su index
				break ;
			}
			i++;	// Pasamos al siguiente número en el array
		}
		current_node = current_node->next;	// Pasamos al siguiente nodo de la pila
	}
	free(arr);
}

