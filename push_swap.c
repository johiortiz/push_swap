/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:26:03 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/30 20:19:39 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	// 1. Maneja el caso de no argumentos
	if (argc < 2)	// Si solo se pasa el nombre del programa
		return (0);	// No hay argumentos para parsear, no es un error
	//2. Leer y validar los argumentos para llenar la pila A.
	// 		Llamar a la función parse_arguments. Esta función debería:
	//		- Convertir los strings de argv a números.
	//		- Crear los nodos y añadirlos a stack_a.
	//		- Validar que sean números válidos, qe no haya dúplicados, etc.
	//		- Si hay un error en el parsing, parse_arguments debería manejarlo
	//			(idealmente llamando a la función exit_error y terminando el programa).
	parse_arguments(argc, argv, &stack_a);
	
	// Después de parse_arguments, si hubo un error fatal, el programa ya habría terminado.
	// Si llegamos aquí, asumimos que stacka se llenado (o está vacía si no se números válidos
	// pero no hubo error fatal, aunque parse_arguments debería salir si no hya números válidos).
	// es una buena idea que parse_arguments también maneje el caso de que, después de procesar,
	// stack_a siga siendo NULL (ej. si los argumentos eran solo espacios), y salga con error.
	// Si stack_a es NULL aquí y no se salió con error, es un caso a considerar.
	if (stack_a == NULL)	// Si despues de parsear no hay nada en A (y no hubo error antes)
		return (0);
	// 3. Comprobar si la pila A ya está ordenada.
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	ft_assign_index(&stack_a);
	ft_sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}