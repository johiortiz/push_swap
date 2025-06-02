/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:37:54 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/02 19:50:18 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	int	stack_size;
	
	stack_size = ft_get_stack_size(*a);
	if (stack_size <= 1 || ft_is_sorted(*a))
		return ;
	else if (stack_size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (stack_size == 3)
		ft_sort_three(a);
	else if (stack_size == 4)
		ft_sort_four(a, b);
	else if (stack_size == 5)
		ft_sort_five(a, b);
	else if (stack_size == 6)
		ft_sort_six(a, b);
	else
	{
		ft_sort_groups(a, b, stack_size);
		ft_sort_back(a, b);
	}
}