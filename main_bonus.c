/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:20 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/04 12:15:27 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_move	get_move_from_line(char *instruction)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		return (MOVE_SA);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		return (MOVE_SB);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		return (MOVE_SS);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		return (MOVE_PA);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		return (MOVE_PB);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		return (MOVE_RA);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		return (MOVE_RB);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		return (MOVE_RR);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		return (MOVE_RRA);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		return (MOVE_RRB);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		return (MOVE_RRR);
	else
		return (0);
}

void	run_instructions(t_stack_node **stack_a)
{
	char			*instruction;
	t_stack_node	*stack_b;
	t_move			move;

	stack_b = NULL;
	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		move = get_move_from_line(instruction);
		if (!move)
		{
			free(instruction);
			free_stack(stack_b);
			return ;
		}
		do_move(move, stack_a, &stack_b, false);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (is_stack_sorted(*stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack;

	if (argc > 1)
	{
		stack = get_stack_from_args(argc, argv);
		if (!stack || stack_has_duplicates(stack))
		{
			if (stack)
				free_stack(stack);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		run_instructions(&stack);
		free_stack(stack);
	}
	return (0);
}
