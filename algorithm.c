/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 15:42:41 by tcharuel         ###   ########.fr       */
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
	if (get_stack_max_index(*stack) == 0)
		do_move(MOVE_SA, stack, NULL);
	else if (get_stack_max_index(*stack) == 1)
		do_move(MOVE_RRA, stack, NULL);
	else
		do_move(MOVE_RA, stack, NULL);
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	while (!is_stack_sorted(*stack_a) || stack_b)
	{
		if (!(*stack_a)->next->next)
			do_move(MOVE_RA, stack_a, &stack_b);
		else if (!(*stack_a)->next->next->next)
			sort_three(stack_a);
		else
		{
		}
		display_stacks(*stack_a, stack_b);
	}
}
