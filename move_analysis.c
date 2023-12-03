/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:14:37 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/03 15:26:20 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_moves_cost(t_stack_node *stack, bool is_stack_a)
{
	int	cost_with_rr;
	int	cost_with_rrr;

	while (stack)
	{
		if (is_stack_a)
		{
			stack->ra_count = get_stack_length(stack, false) - 1;
			stack->rb_count = get_stack_length(stack->target_node, false) - 1;
			stack->rra_count = get_stack_length(stack, true);
			stack->rrb_count = get_stack_length(stack->target_node, true);
		}
		else
		{
			stack->ra_count = get_stack_length(stack->target_node, false) - 1;
			stack->rb_count = get_stack_length(stack, false) - 1;
			stack->rra_count = get_stack_length(stack->target_node, true);
			stack->rrb_count = get_stack_length(stack, true);
		}
		cost_with_rr = MAX(stack->ra_count, stack->rb_count);
		cost_with_rrr = MAX(stack->rra_count, stack->rrb_count);
		if (cost_with_rr < cost_with_rrr && cost_with_rr < (stack->ra_count
				+ stack->rrb_count) && cost_with_rr < (stack->rra_count
				+ stack->rb_count))
		{
			stack->rra_count = 0;
			stack->rrb_count = 0;
			stack->move_cost = cost_with_rr;
		}
		else if (cost_with_rrr < cost_with_rr && cost_with_rrr < stack->ra_count
			+ stack->rrb_count && cost_with_rrr < stack->rra_count
			+ stack->rb_count)
		{
			stack->ra_count = 0;
			stack->rb_count = 0;
			stack->move_cost = cost_with_rrr;
		}
		else if (stack->ra_count + stack->rrb_count < stack->rra_count
			+ stack->rb_count)
		{
			stack->rb_count = 0;
			stack->rra_count = 0;
			stack->move_cost = stack->ra_count + stack->rrb_count;
		}
		else
		{
			stack->ra_count = 0;
			stack->rrb_count = 0;
			stack->move_cost = stack->rb_count + stack->rra_count;
		}
		stack = stack->next;
	}
}

void	set_target_nodes(t_stack_node *stack_from, t_stack_node *stack_to)
{
	t_stack_node	*target_stack;

	while (stack_from)
	{
		target_stack = stack_to;
		stack_from->target_node = target_stack;
		while (target_stack)
		{
			if ((target_stack->number < stack_from->number
					&& (target_stack->number > stack_from->target_node->number
						|| stack_from->target_node->number > stack_from->number))
				|| (stack_from->target_node->number > stack_from->number
					&& target_stack->number > stack_from->target_node->number))
				stack_from->target_node = target_stack;
			target_stack = target_stack->next;
		}
		stack_from = stack_from->next;
	}
}
