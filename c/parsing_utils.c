/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 01:25:13 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/02 19:19:10 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_ps(const char *str)
{
	long	result;
	int		sign;
	int		i;
	
	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0' || !(str[i] >= '0' && str[i] <= '9'))
		ft_error_exit(NULL, NULL);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_error_exit(NULL, NULL);
	return (result * sign);
}

void	ft_add_number_to_stack(t_stack **stack, int number, int index_val)
{
	t_stack	*node;

	node = ft_new_node(number, index_val);
	ft_stack_add_bottom(stack, node);
}


bool	ft_string_contains_only_valid_chars(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (false);
	}
	while(str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_valid_char(char c)
{
	return (c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

void	ft_free_split_result(char **arr)
{
	int	i;

	if (arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}
