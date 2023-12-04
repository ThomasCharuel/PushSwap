/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:14:37 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 11:21:09 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotations_count(t_stack_node *node, bool is_stack_a)
{
	if (is_stack_a)
	{
		node->ra_count = get_stack_length(node, false) - 1;
		node->rb_count = get_stack_length(node->target_node, false) - 1;
		node->rra_count = get_stack_length(node, true);
		node->rrb_count = get_stack_length(node->target_node, true);
	}
	else
	{
		node->ra_count = get_stack_length(node->target_node, false) - 1;
		node->rb_count = get_stack_length(node, false) - 1;
		node->rra_count = get_stack_length(node->target_node, true);
		node->rrb_count = get_stack_length(node, true);
	}
}

void	set_node_moves(t_stack_node *node, int cost_with_rr, int cost_with_rrr)
{
	if (cost_with_rr == node->move_cost)
	{
		node->rra_count = 0;
		node->rrb_count = 0;
	}
	else if (cost_with_rrr == node->move_cost)
	{
		node->ra_count = 0;
		node->rb_count = 0;
	}
	else if (node->ra_count + node->rrb_count == node->move_cost)
	{
		node->rb_count = 0;
		node->rra_count = 0;
	}
	else
	{
		node->ra_count = 0;
		node->rrb_count = 0;
	}
}

void	set_moves_cost(t_stack_node *stack, bool is_stack_a)
{
	int	cost_with_rr;
	int	cost_with_rrr;

	while (stack)
	{
		set_rotations_count(stack, is_stack_a);
		cost_with_rr = ft_max(2, stack->ra_count, stack->rb_count);
		cost_with_rrr = ft_max(2, stack->rra_count, stack->rrb_count);
		stack->move_cost = ft_min(4, cost_with_rr, cost_with_rrr,
				stack->ra_count + stack->rrb_count, stack->rra_count
				+ stack->rb_count);
		set_node_moves(stack, cost_with_rr, cost_with_rrr);
		stack = stack->next;
	}
}

bool	should_be_new_target_node(int node_number, int current_target_number,
		int candidate_target_number, bool is_stack_a)
{
	if (is_stack_a)
	{
		if (candidate_target_number < node_number
			&& (candidate_target_number > current_target_number
				|| current_target_number > node_number))
			return (true);
		if (current_target_number > node_number
			&& candidate_target_number > current_target_number)
			return (true);
	}
	else
	{
		if (candidate_target_number > node_number
			&& (candidate_target_number < current_target_number
				|| current_target_number < node_number))
			return (true);
		if (current_target_number < node_number
			&& candidate_target_number < current_target_number)
			return (true);
	}
	return (false);
}

void	set_target_nodes(t_stack_node *stack_from, t_stack_node *stack_to,
		bool is_stack_a)
{
	t_stack_node	*target_stack;

	while (stack_from)
	{
		target_stack = stack_to;
		stack_from->target_node = target_stack;
		while (target_stack)
		{
			if (should_be_new_target_node(stack_from->number,
					stack_from->target_node->number, target_stack->number,
					is_stack_a))
				stack_from->target_node = target_stack;
			target_stack = target_stack->next;
		}
		stack_from = stack_from->next;
	}
}
