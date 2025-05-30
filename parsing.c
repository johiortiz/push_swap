/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:56:25 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/30 22:33:13 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Este archivo se centrará en la validación y conversión de cadenas de caracetres individuales
#include "push_swap.h"

void	ft_add_number_to_stack(t_stack **stack, int number, int index_val)
{
	t_stack	*node;

	node = new_node(number, index_val);
	ft_stack_add_bottom(stack, node);
}

void	ft_check_duplicates(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
				exit_error(&stack_a, NULL);
			runner = runner->next;
		}
		current = current->next;
	}
}

// Toma una cadena num_str, la valida, la convierte a int y a añade a stack_a.
// Si hay un error, llama ft_exit_error. El tercer parámetro es para poder liberar
// la memoria de ft_split si esta función es llamada desde el contexto donde se usó ft_split
// y ocurre un error.
static void	ft_process_single_number_str(const char *num_str, t_stack **stack_a, char **arr)
{
	long	num_long;	// Para la conversión intermedia a long
	int		num_int;	// Para el valor int final

	// Validar el formato del string
	if (!ft_string_contains_only_valid_chars(num_str))
	{
		if (arr)
			ft_free_split_result(arr);
		ft_error_exit(stack_a, NULL);
	}
	num_long = ft_atol_ps(num_str);
	// Validar que el número esté en el rango de un int
	if (num_long > INT_MAX || num_long < INT_MIN)
	{
		if (arr)
			ft_free_split_result(arr);
		ft_error_exit(stack_a, NULL);
	}
	num_int = (int)num_long;	// convierte a int
	// Añadir el número a la pila
	ft_add_number_to_stack(stack_a, num_int, 0);
}

// Maneja el caso donde todos los números vienen en un solo string arg_str(que era argv[i])
static void	ft_parse_string_with_spaces(const char	*arg_str, t_stack **stack_a)
{
	char	**numbers_arr;		// Para guardar el resultado de ft_split
	int		k;

	numbers_arr = ft_split(arg_str, ' ');
	if (!numbers_arr)
		ft_error_exit(stack_a, NULL);
	if (numbers_arr[0] == NULL)
	{
		ft_split(numbers_arr);
		ft_exit_error(stack_a, NULL);
	}
	k = 0;
	while (numbers_arr[k] != NULL)
	{
		ft_process_single_number_str(numbers_arr[k], stack_a, numbers_arr);
		k++;
	}
	ft_free_split_result(numbers_arr);
}

static void	parse_individual_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	 i = 1;
	 while (i < argc)
	 {
		ft_process_single_number_str(argv[i]);
		i++;
	 }
}

void	ft_parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	if (argc == 2 && ft_strchr(argv[1], ' '))
		ft_parse_string_with_spaces(argv[1], stack_a);
	else
		ft_parse_arguments(argc, argv, stack_a);
	if (*stack_a == NULL)
		ft_exit_error(stack_a, NULL);
	ft_check_duplicates(*stack_a);
}

