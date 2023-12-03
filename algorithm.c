/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/03 15:31:38 by tcharuel         ###   ########.fr       */
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

void	sort_three(t_stack_node **stack)
{
	while (!is_stack_sorted(*stack))
	{
		if (get_stack_max_index(*stack) == 0)
			do_move(MOVE_SA, stack, NULL);
		else if (get_stack_max_index(*stack) == 1)
			do_move(MOVE_RRA, stack, NULL);
		else
			do_move(MOVE_RA, stack, NULL);
	}
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
			do_move(MOVE_RR, stack_a, stack_b);
			node->ra_count--;
			node->rb_count--;
		}
		else if (node->ra_count)
		{
			do_move(MOVE_RA, stack_a, stack_b);
			node->ra_count--;
		}
		else
		{
			do_move(MOVE_RB, stack_a, stack_b);
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
			do_move(MOVE_RRR, stack_a, stack_b);
			node->rra_count--;
			node->rrb_count--;
		}
		else if (node->rra_count)
		{
			do_move(MOVE_RRA, stack_a, stack_b);
			node->rra_count--;
		}
		else
		{
			do_move(MOVE_RRB, stack_a, stack_b);
			node->rrb_count--;
		}
	}
}

static void	move_optimal_node(t_stack_node **stack_from,
		t_stack_node **stack_to, bool move_from_a)
{
	t_stack_node	*optimal_node;

	set_target_nodes(*stack_from, *stack_to);
	set_moves_cost(*stack_from, move_from_a);
	optimal_node = get_optimal_node_to_move(*stack_from);
	do_r_moves(optimal_node, stack_from, stack_to);
	do_rr_moves(optimal_node, stack_from, stack_to);
	if (move_from_a)
		do_move(MOVE_PB, stack_from, stack_to);
	else
		do_move(MOVE_PA, stack_to, stack_from);
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (!is_stack_sorted(*stack_a))
	{
		if (!(*stack_a)->next->next)
			do_move(MOVE_RA, stack_a, &stack_b);
		else if (!(*stack_a)->next->next->next)
			sort_three(stack_a);
		else
		{
			do_move(MOVE_PB, stack_a, &stack_b);
			while (get_stack_length(*stack_a, false) > 3)
				move_optimal_node(stack_a, &stack_b, true);
			sort_three(stack_a);
			display_stacks(*stack_a, stack_b);
			while (stack_b)
				move_optimal_node(&stack_b, stack_a, false);
			display_stacks(*stack_a, stack_b);
		}
	}
}
