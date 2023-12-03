/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:18:36 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/03 16:28:51 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_stack(t_stack_node *stack)
{
	if (!stack)
		return ;
	display_stack(stack->next);
	if (stack->prev && stack->next)
		ft_printf("%d <--- %d ---> %d\n", stack->prev->number, stack->number,
			stack->next->number);
	else if (stack->prev)
		ft_printf("%d <--- %d\n", stack->prev->number, stack->number);
	else if (stack->next)
		ft_printf("           %d ---> %d\n", stack->number,
			stack->next->number);
	else
		ft_printf("           %d\n", stack->number);
}

void	display_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	ft_printf("Stack A:\n--\n");
	display_stack(stack_a);
	ft_printf("--\nStack B:\n--\n");
	display_stack(stack_b);
	ft_printf("--\n");
}
