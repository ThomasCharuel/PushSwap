/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:38:28 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 14:46:34 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	prepend_to_stack(t_stack_node **stack, int number)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (-1);
	new_node->number = number;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (1);
}

int	append_to_stack(t_stack_node **stack, int number)
{
	t_stack_node	*new_node;
	t_stack_node	*node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (-1);
	new_node->number = number;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new_node;
		new_node->prev = node;
	}
	return (1);
}

int	get_stack_length(t_stack_node *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

void	free_stack(t_stack_node *stack)
{
	if (stack->next)
		free_stack(stack->next);
	free(stack);
}
