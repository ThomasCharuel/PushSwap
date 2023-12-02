/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 15:04:30 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	display_stacks(*stack_a, stack_b);
	do_move(MOVE_RRA, stack_a, &stack_b);
	display_stacks(*stack_a, stack_b);
	do_move(MOVE_RRA, stack_a, &stack_b);
	display_stacks(*stack_a, stack_b);
	if (stack_b)
		ft_printf("Stack B not empty\n");
}
