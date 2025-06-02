/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:11:56 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/02 19:43:05 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;
	
	if (!a || !*a || !(*a)->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	
	if (x > y && y < z)
	{
		if (x < z)
			rra(a);
		else
			ra(a);
	}
	else if (x > y && x > z)
		ra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}


void	ft_sort_four(t_stack **a, t_stack **b)
{
	int current_size;
	int	smallest;

	current_size = ft_get_stack_size(*a);
	if (current_size != 4)
		return ;
	if (ft_is_sorted(*a))
		return ;
	smallest = ft_position_smallest_value(*a);
	ft_rotate_to_smallest_on_top(a, smallest, current_size);
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	current_size;
	int	smallest_pos;
	
	current_size = ft_get_stack_size(*a);
	if (current_size != 5)
		return ;
	if (ft_is_sorted(*a))
		return ;
	smallest_pos = ft_position_smallest_value(*a);
	ft_rotate_to_smallest_on_top(a,smallest_pos, current_size);
	pb(a, b);
	ft_sort_four(a, b);
	pa(a, b);
}

void	ft_sort_six(t_stack **a, t_stack **b)
{
	int current_size;
	int	smallest_pos;
	
	current_size = ft_get_stack_size(*a);
	if (current_size != 6)
		return ;
	if (ft_is_sorted(*a))
		return ;
	smallest_pos = ft_position_smallest_value(*a);
	ft_rotate_to_smallest_on_top(a, smallest_pos, current_size);
	pb(a, b);
	ft_sort_five(a, b);
	pa(a, b);
}
