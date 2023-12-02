/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:25:22 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 14:14:30 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_stack_node **stack)
{
	int				length;
	t_stack_node	*node;

	node = *stack;
	length = get_stack_length(*stack);
	if (length < 2)
		return ;
	else if (length == 2)
	{
		*stack = (*stack)->next;
		node = *stack;
	}
	else
	{
		node = *stack;
		while (node->next->next->next)
			node = node->next;
		node->next = node->next->next;
		node = node->next;
	}
	node->next = node->prev;
	node->prev = NULL;
	node->next->prev = *stack;
	node->next->next = NULL;
}

static void	stack_push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

static void	stack_rotate(t_stack_node **stack, bool reverse)
{
	(void)reverse;
	(void)stack;
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

void	do_move(t_move move, t_stack_node **stack_a, t_stack_node **stack_b)
{
	print_move(move);
	if (move == MOVE_SA || move == MOVE_SS)
		stack_swap(stack_a);
	if (move == MOVE_SB || move == MOVE_SS)
		stack_swap(stack_b);
	if (move == MOVE_PA)
		stack_push(stack_a, stack_b);
	if (move == MOVE_PB)
		stack_push(stack_b, stack_a);
	if (move == MOVE_RA || move == MOVE_RR)
		stack_rotate(stack_a, false);
	if (move == MOVE_RB || move == MOVE_RR)
		stack_rotate(stack_b, false);
	if (move == MOVE_RRA || move == MOVE_RRR)
		stack_rotate(stack_a, true);
	if (move == MOVE_RRB || move == MOVE_RRR)
		stack_rotate(stack_b, true);
}
