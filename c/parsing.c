/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:56:25 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/03 19:11:30 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				ft_error_exit(&stack_a, NULL);
			runner = runner->next;
		}
		current = current->next;
	}
}

static void	ft_process_single_number_str(const char *num_str, t_stack **stack_a, char **arr)
{
	long	num_long;
	int		num_int;

	if (!ft_string_contains_only_valid_chars(num_str))
	{
		if (arr)
			ft_free_split_result(arr);
		ft_error_exit(stack_a, NULL);
	}
	num_long = ft_atol_ps(num_str);
	if (num_long > INT_MAX || num_long < INT_MIN)
	{
		if (arr)
			ft_free_split_result(arr);
		ft_error_exit(stack_a, NULL);
	}
	num_int = (int)num_long;
	ft_add_number_to_stack(stack_a, num_int, 0);
}

static void	ft_parse_string_with_spaces(const char	*arg_str, t_stack **stack_a)
{
	char	**numbers_arr;
	int		k;

	numbers_arr = ft_split(arg_str, ' ');
	if (!numbers_arr)
		ft_error_exit(stack_a, NULL);
	if (numbers_arr[0] == NULL)
		ft_error_exit(stack_a, NULL);
	k = 0;
	while (numbers_arr[k] != NULL)
	{
		ft_process_single_number_str(numbers_arr[k], stack_a, numbers_arr);
		k++;
	}
	ft_free_split_result(numbers_arr);
}

static void	ft_parse_individual_arguments(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_process_single_number_str(argv[i], stack_a, NULL);
		i++;
	}
}

void	ft_parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	if (argc == 2 && ft_strchr(argv[1], ' '))
		ft_parse_string_with_spaces(argv[1], stack_a);
	else
		ft_parse_individual_arguments(argc, argv, stack_a);
	if (*stack_a == NULL)
		ft_error_exit(stack_a, NULL);
	ft_check_duplicates(*stack_a);
}

