/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:14:37 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 19:25:26 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_moves_cost(t_stack_node *stack_a)
{
	int	ra_count;
	int	rb_count;

	while (stack_a)
	{
		ra_count = get_stack_length(stack_a) - 1;
		rb_count = get_stack_length(stack_a->target_node) - 1;
		// rra_count = get_stack_length(stack_a);
		// rrb_count = get_stack_length(stack_a->target_node);
		stack_a->move_cost = MAX(ra_count, rb_count);
		stack_a->ra_count = ra_count;
		stack_a->rb_count = rb_count;
		stack_a = stack_a->next;
	}
}

void	set_target_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*target_stack;

	while (stack_a)
	{
		target_stack = stack_b;
		stack_a->target_node = target_stack;
		while (target_stack)
		{
			if ((target_stack->number < stack_a->number
					&& target_stack->number > stack_a->target_node->number)
				|| (target_stack->number > stack_a->number
					&& stack_a->target_node->number > stack_a->number))
				stack_a->target_node = target_stack;
			target_stack = target_stack->next;
		}
		stack_a = stack_a->next;
	}
}
