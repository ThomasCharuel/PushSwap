/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:09:19 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 10:55:27 by tcharuel         ###   ########.fr       */
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

static void	move_optimal_node(t_stack_node **stack_from,
		t_stack_node **stack_to, bool move_from_a)
{
	t_stack_node	*optimal_node;

	set_target_nodes(*stack_from, *stack_to, move_from_a);
	set_moves_cost(*stack_from, move_from_a);
	optimal_node = get_optimal_node_to_move(*stack_from);
	if (move_from_a)
	{
		do_r_moves(optimal_node, stack_from, stack_to);
		do_rr_moves(optimal_node, stack_from, stack_to);
		do_move(MOVE_PB, stack_from, stack_to);
	}
	else
	{
		do_r_moves(optimal_node, stack_to, stack_from);
		do_rr_moves(optimal_node, stack_to, stack_from);
		do_move(MOVE_PA, stack_to, stack_from);
	}
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
			while (stack_b)
				move_optimal_node(&stack_b, stack_a, false);
			rotate_stack_until_ordered(stack_a);
		}
	}
}
