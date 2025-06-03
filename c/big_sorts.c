/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:15:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/03 19:11:15 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i * i) <= n)
		i++;
	i--;
	return (i);
}

static void	ft_process_group(t_stack **a, t_stack **b, int *index_count, int size)
{
	if ((*a)->index <= *index_count)
	{
		pb(a, b);
		rb(b);
		(*index_count)++;
	}
	else if ((*a)->index <= *index_count + size)
	{
		pb(a, b);
		(*index_count)++;
	}
	else
		ra(a);
}

void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg)
{
	int	index_count;
	int	size;

	if (n_arg == 0 || !(*a))
		return ;
	index_count = 0;
	size = (ft_sqrt(n_arg) * 124 / 100);
	if (size == 0)
		size = n_arg;
	while (*a != NULL)
		ft_process_group(a, b, &index_count, size);
}

static int	ft_biggest_index_pos(t_stack *stack)
{
	int		bigger_index;
	int		bigger_pos;
	int		current_pos;
	t_stack	*current_node;

	if (!stack)
		return (-1);
	bigger_index = stack->index;
	bigger_pos = 0;
	current_pos = 0;
	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->index > bigger_index)
		{
			bigger_index = current_node->index;
			bigger_pos = current_pos;
		}
		current_node = current_node->next;
		current_pos++;
	}
	return (bigger_pos);
}

void	ft_sort_back(t_stack **a, t_stack **b)
{
	int	b_index_pos;
	int	b_current_size;
	int	i;

	while (*b != NULL)
	{
		b_index_pos = ft_biggest_index_pos(*b);
		b_current_size = ft_get_stack_size(*b);
		i = 0;
		if (b_index_pos > 0)
		{
			if (b_index_pos <= b_current_size / 2)
				while (i++ < b_index_pos)
					rb(b);
			else
				while (i++ < b_current_size - b_index_pos)
					rrb(b);
		}
		pa(a, b);
	}
}
