/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:41:38 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/02 19:53:21 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_copy_stack_to_array(t_stack *stack, int *arr, int size)
{
	int	i;
	t_stack	*current_node;

	current_node = stack;
	i = 0;
	while (i < size)
	{
		arr[i] = current_node->value;
		current_node = current_node->next;
		i++;
	}
}

static void	ft_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	ft_assign_index_from_sorted_array(t_stack *stack, int *arr, int size)
{
	t_stack	*current_node;
	int	i;

	current_node = stack;
	while (current_node != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current_node->value == arr[i])
			{
				current_node->index = i;
				break ;
			}
			i++;
		}
		current_node = current_node->next;
	}
}

void	ft_assign_index(t_stack *stack_a)
{
	int	size;
	int	*arr;

	if (!stack_a)
		return ;
	size = ft_get_stack_size(stack_a);
	if (size == 0)
		return ;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		ft_error_exit(NULL, NULL);
		return ;
	}
	ft_copy_stack_to_array(stack_a, arr, size);
	ft_sort_array(arr, size);
	ft_assign_index_from_sorted_array(stack_a, arr, size);
	free(arr);
}