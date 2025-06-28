/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:47:02 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/17 20:32:51 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_smallest_on_top(t_stack **a, int smallest_pos,
		int stack_size)
{
	int	rot_count;

	if (smallest_pos == 0)
		return ;
	if (smallest_pos <= stack_size / 2)
	{
		rot_count = smallest_pos;
		while (rot_count > 0)
		{
			ra(a);
			rot_count--;
		}
	}
	else
	{
		rot_count = stack_size - smallest_pos;
		while (rot_count > 0)
		{
			rra(a);
			rot_count--;
		}
	}
}

int	ft_position_smallest_value(t_stack *stack_a)
{
	t_stack	*current_node;
	int		min_value;
	int		min_pos;
	int		current_pos;

	current_node = stack_a;
	if (!current_node)
		return (-1);
	min_value = current_node->value;
	min_pos = 0;
	current_pos = 0;
	while (current_node != NULL)
	{
		if (current_node->value < min_value)
		{
			min_value = current_node->value;
			min_pos = current_pos;
		}
		current_pos++;
		current_node = current_node->next;
	}
	return (min_pos);
}
