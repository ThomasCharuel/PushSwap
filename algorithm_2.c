/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 12:49:37 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_max_index(t_stack_node *stack)
{
	int	max;
	int	max_index;
	int	index;

	max = stack->number;
	index = 0;
	max_index = index;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (max_index);
}

t_stack_node	*get_optimal_node_to_move(t_stack_node *stack)
{
	t_stack_node	*optimal_node;

	optimal_node = stack;
	while (stack)
	{
		if (stack->move_cost < optimal_node->move_cost)
			optimal_node = stack;
		stack = stack->next;
	}
	return (optimal_node);
}

void	do_r_moves(t_stack_node *node, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	while (node->ra_count || node->rb_count)
	{
		if (node->ra_count && node->rb_count)
		{
			do_move(MOVE_RR, stack_a, stack_b, true);
			node->ra_count--;
			node->rb_count--;
		}
		else if (node->ra_count)
		{
			do_move(MOVE_RA, stack_a, stack_b, true);
			node->ra_count--;
		}
		else
		{
			do_move(MOVE_RB, stack_a, stack_b, true);
			node->rb_count--;
		}
	}
}

void	do_rr_moves(t_stack_node *node, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	while (node->rra_count || node->rrb_count)
	{
		if (node->rra_count && node->rrb_count)
		{
			do_move(MOVE_RRR, stack_a, stack_b, true);
			node->rra_count--;
			node->rrb_count--;
		}
		else if (node->rra_count)
		{
			do_move(MOVE_RRA, stack_a, stack_b, true);
			node->rra_count--;
		}
		else
		{
			do_move(MOVE_RRB, stack_a, stack_b, true);
			node->rrb_count--;
		}
	}
}

void	rotate_stack_until_ordered(t_stack_node **stack)
{
	int	stack_max_index;
	int	stack_length;

	stack_max_index = get_stack_max_index(*stack);
	stack_length = get_stack_length(*stack, false);
	if (stack_max_index < stack_length / 2)
	{
		while (stack_max_index)
		{
			do_move(MOVE_RRA, stack, NULL, true);
			stack_max_index--;
		}
	}
	else
	{
		while (stack_max_index < stack_length)
		{
			do_move(MOVE_RA, stack, NULL, true);
			stack_max_index++;
		}
	}
}
