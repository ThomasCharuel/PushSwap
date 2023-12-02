/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 15:13:01 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_stack_node *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->number < stack_a->next->number)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	ft_printf("Stack is sorted: %d\n", is_stack_sorted(*stack_a));
	display_stacks(*stack_a, stack_b);
	do_move(MOVE_RRA, stack_a, &stack_b);
	display_stacks(*stack_a, stack_b);
	do_move(MOVE_RRA, stack_a, &stack_b);
	display_stacks(*stack_a, stack_b);
	ft_printf("Stack is sorted: %d\n", is_stack_sorted(*stack_a));
	if (stack_b)
		ft_printf("Stack B not empty\n");
}
