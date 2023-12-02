/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:13:03 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 17:12:26 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static t_stack_node	*get_stack_from_str(char *str)
{
	t_stack_node	*stack;
	char			**int_arr;
	size_t			i;
	int				parsed_number;

	int_arr = ft_split(str, ' ');
	if (!int_arr)
		return (NULL);
	stack = NULL;
	i = 0;
	while (int_arr[i])
	{
		parsed_number = ft_atoi(int_arr[i]);
		if ((long)parsed_number != ft_atol(int_arr[i])
			|| !is_str_numeric(int_arr[i]) || prepend_to_stack(&stack,
				parsed_number) < 0)
		{
			free_stack(stack);
			free_strs(int_arr);
			return (NULL);
		}
		i++;
	}
	free_strs(int_arr);
	return (stack);
}

static t_stack_node	*get_stack_from_strs(int str_count, char **strs)
{
	t_stack_node	*stack;
	int				i;
	int				parsed_number;

	stack = NULL;
	i = 0;
	while (i < str_count)
	{
		parsed_number = ft_atoi(strs[i]);
		if ((long)parsed_number != ft_atol(strs[i]) || !is_str_numeric(strs[i])
			|| prepend_to_stack(&stack, parsed_number) < 0)
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

t_stack_node	*get_stack_from_args(int argc, char **argv)
{
	if (argc == 2)
		return (get_stack_from_str(argv[1]));
	else
		return (get_stack_from_strs(argc - 1, &argv[1]));
}
