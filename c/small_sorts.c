/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:11:56 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/03 19:15:18 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;
	
	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	
	if (x > y && y > z)        // 3 2 1
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)  // 3 1 2
		ra(a);
	else if (x > y && y < z && x < z)  // 2 1 3
		sa(a);
	else if (x < y && y > z && x > z)  // 2 3 1
		rra(a);
	else if (x < y && y > z && x < z)  // 1 3 2
	{
		sa(a);
		ra(a);
	}
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
