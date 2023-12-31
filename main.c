/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:20 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 16:00:09 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;

	if (argc > 1)
	{
		stack_a = get_stack_from_args(argc, argv);
		if (!stack_a || stack_has_duplicates(stack_a))
		{
			if (stack_a)
				free_stack(stack_a);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		sort_stack(&stack_a);
		free_stack(stack_a);
	}
	return (0);
}
