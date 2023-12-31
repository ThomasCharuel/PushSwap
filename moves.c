/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:25:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 12:14:39 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_stack_node **stack)
{
	int				length;
	t_stack_node	*before_last_node;
	t_stack_node	*last_node;

	before_last_node = *stack;
	length = get_stack_length(*stack, false);
	if (length < 2)
		return ;
	else if (length == 2)
	{
		last_node = (*stack)->next;
		*stack = last_node;
		last_node->prev = NULL;
	}
	else
	{
		while (before_last_node->next->next)
			before_last_node = before_last_node->next;
		last_node = before_last_node->next;
		before_last_node->prev->next = last_node;
		last_node->prev = before_last_node->prev;
	}
	last_node->next = before_last_node;
	before_last_node->next = NULL;
	before_last_node->prev = last_node;
}

static void	stack_push(t_stack_node **stack_from, t_stack_node **stack_to)
{
	t_stack_node	*stack_to_last_node;
	t_stack_node	*stack_from_last_node;

	stack_from_last_node = get_last_node(*stack_from);
	if (!stack_from_last_node)
		return ;
	if (stack_from_last_node->prev)
		stack_from_last_node->prev->next = NULL;
	else
		*stack_from = NULL;
	stack_to_last_node = get_last_node(*stack_to);
	if (stack_to_last_node)
		stack_to_last_node->next = stack_from_last_node;
	else
		*stack_to = stack_from_last_node;
	stack_from_last_node->prev = stack_to_last_node;
}

static void	stack_rotate(t_stack_node **stack, bool reverse)
{
	t_stack_node	*last_node;

	if (get_stack_length(*stack, false) < 2)
		return ;
	last_node = get_last_node(*stack);
	if (reverse)
	{
		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_node->next->next = NULL;
	}
	else
	{
		last_node->prev->next = NULL;
		last_node->prev = NULL;
		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}

static void	print_move(t_move move)
{
	if (move == MOVE_SA)
		ft_printf("sa\n");
	else if (move == MOVE_SB)
		ft_printf("sb\n");
	else if (move == MOVE_SS)
		ft_printf("ss\n");
	else if (move == MOVE_PA)
		ft_printf("pa\n");
	else if (move == MOVE_PB)
		ft_printf("pb\n");
	else if (move == MOVE_RA)
		ft_printf("ra\n");
	else if (move == MOVE_RB)
		ft_printf("rb\n");
	else if (move == MOVE_RR)
		ft_printf("rr\n");
	else if (move == MOVE_RRA)
		ft_printf("rra\n");
	else if (move == MOVE_RRB)
		ft_printf("rrb\n");
	else if (move == MOVE_RRR)
		ft_printf("rrr\n");
}

void	do_move(t_move move, t_stack_node **stack_a, t_stack_node **stack_b,
		bool should_print)
{
	if (should_print)
		print_move(move);
	if (move == MOVE_SA || move == MOVE_SS)
		stack_swap(stack_a);
	if (move == MOVE_SB || move == MOVE_SS)
		stack_swap(stack_b);
	if (move == MOVE_PA)
		stack_push(stack_b, stack_a);
	if (move == MOVE_PB)
		stack_push(stack_a, stack_b);
	if (move == MOVE_RA || move == MOVE_RR)
		stack_rotate(stack_a, false);
	if (move == MOVE_RB || move == MOVE_RR)
		stack_rotate(stack_b, false);
	if (move == MOVE_RRA || move == MOVE_RRR)
		stack_rotate(stack_a, true);
	if (move == MOVE_RRB || move == MOVE_RRR)
		stack_rotate(stack_b, true);
}
