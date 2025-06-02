/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:53:07 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/02 19:52:31 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value, int index_value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_error_exit(NULL, NULL);
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


