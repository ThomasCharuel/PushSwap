/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_constraints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:53:31 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 13:00:04 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	stack_has_value(t_stack_node *stack, int value)
{
	while (stack)
	{
		if (stack->number == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	stack_has_duplicates(t_stack_node *stack)
{
	while (stack)
	{
		if (stack_has_value(stack->next, stack->number))
			return (true);
		stack = stack->next;
	}
	return (false);
}

bool	arg_has_correct_format(int parsed_number, char *str)
{
	int	i;
	int	digit_count;

	if ((long)parsed_number != ft_atol(str))
		return (false);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	digit_count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			digit_count++;
		else
			return (false);
		i++;
	}
	return (digit_count > 0 && digit_count <= 10);
}
