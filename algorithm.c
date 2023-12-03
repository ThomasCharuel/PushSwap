/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/03 12:37:55 by tcharuel         ###   ########.fr       */
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

static void	push_optimal_node_from_a_to_b(t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	t_stack_node	*optimal_node;
	t_stack_node	*node;

	set_target_nodes(*stack_a, *stack_b);
	set_moves_cost(*stack_a);
	optimal_node = *stack_a;
	node = *stack_a;
	while (node)
	{
		if (node->move_cost < optimal_node->move_cost)
			optimal_node = node;
		node = node->next;
	}
	while (optimal_node->ra_count || optimal_node->rb_count)
	{
		if (optimal_node->ra_count && optimal_node->rb_count)
		{
			do_move(MOVE_RR, stack_a, stack_b);
			optimal_node->ra_count--;
			optimal_node->rb_count--;
		}
		else if (optimal_node->ra_count)
		{
			do_move(MOVE_RA, stack_a, stack_b);
			optimal_node->ra_count--;
		}
		else if (optimal_node->rb_count)
		{
			do_move(MOVE_RB, stack_a, stack_b);
			optimal_node->rb_count--;
		}
	}
	do_move(MOVE_PB, stack_a, stack_b);
	display_stacks(*stack_a, *stack_b);
}

static void	push_optimal_node_from_b_to_a(t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	do_move(MOVE_PA, stack_a, stack_b);
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	display_stacks(*stack_a, stack_b);
	if (!is_stack_sorted(*stack_a))
	{
		if (!(*stack_a)->next->next)
			do_move(MOVE_RA, stack_a, &stack_b);
		else if (!(*stack_a)->next->next->next)
			sort_three(stack_a);
		else
		{
			do_move(MOVE_PB, stack_a, &stack_b);
			while (get_stack_length(*stack_a) > 3)
				push_optimal_node_from_a_to_b(stack_a, &stack_b);
			display_stacks(*stack_a, stack_b);
			sort_three(stack_a);
			while (stack_b)
				push_optimal_node_from_b_to_a(stack_a, &stack_b);
			// Set proper order by rotating as needed.
			// Utiliser la mediane pour savoir dans quel sens il faut sort
		}
	}
}
