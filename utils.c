/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 04:47:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/17 20:14:18 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(t_stack **a, t_stack **b)
{
	if (a && *a)
		ft_free_stack(a);
	if (b && *b)
		ft_free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
