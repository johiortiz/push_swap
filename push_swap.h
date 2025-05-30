/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:46:02 by johyorti          #+#    #+#             */
/*   Updated: 2025/05/30 22:24:23 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;
	struct	s_stack 	*next;
}	t_stack;

// Initialization & Parsing (parsing.c and push_swap.c)
void	ft_parse_arguments(int argc, char **argv, t_stack **stack_a);
long	ft_atol_ps(const char *str);
void	ft_chceck_duplicates(t_stack *stack_a);
void	ft_add_number_to_stack(t_stack **stack, int number, int index_val);
void	ft_free_split_result(char **arr);
bool	ft_string_contains_only_valid_chars(const char *str);
bool	ft_is_valid_char(char c);
static void	ft_process_single_number_str(const char *num_str, t_stack **stack_a, char **arr);
static void	ft_parse_string_with_spaces(const char	*arg_str, t_stack **stack_a);


// Node/Stack Utils (stack_utils.c)
t_stack	*ft_new_node(int value, int index_val);
void	ft_stack_add_bottom(t_stack **stack_head, t_stack *new_node_to_add);
void	ft_stack_add_top(t_stack **stack_head, t_stack *new_node_to_add);
t_stack	*ft_stack_pop(t_stack **stack_head);
void	ft_free_stack(t_stack **stack_head);
int		ft_get_stack_size(t_stack *head);
bool	ft_is_sorted(t_stack *stack_a);
void	ft_assign_index(t_stack *stack_a, int count);

// Movements
// Swap
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// Push
void	pa(t_stack **stack_a);
void	pb(t_stack **stack_b);

// Rotate
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// Reverse Rotate
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Sorts
// Short Sorts
static int	ft_position_smallet_value(t_stack *stack_a);
void	ft_sort_three(stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);

// Big sorts
static int	ft_sqrt(int n);
void	ft_sort_groups(t_stack **a t_stack **b, int n_arg);
static int	ft_biggest_index_pos(t_stack *stack);
void	ft_sort_back(t_stack **a, t_stack **b);

// Stack Sort
void	ft_sort_stack(t_stack **a, t_stack **b);


// Utils (utils.c)
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b);

#endif