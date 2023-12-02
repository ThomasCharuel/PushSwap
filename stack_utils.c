/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:38:28 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 12:17:26 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack_node *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->number);
		stack = stack->next;
	}
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
	}
	return (1);
}

void	free_stack(t_stack_node *stack)
{
	if (stack->next)
		free_stack(stack->next);
	free(stack);
}
