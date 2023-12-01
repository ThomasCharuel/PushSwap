/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:20 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/01 19:13:23 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_item(void *content)
{
	ft_printf("%d\n", *((int *)content));
}

t_list	*get_stack_from_str(char *str)
{
	t_list	*lst;
	t_list	*new_node;
	char	**int_arr;
	size_t	i;
	int		*content;

	int_arr = ft_split(str, ' ');
	if (!int_arr)
		return (NULL);
	lst = NULL;
	i = 0;
	while (int_arr[i])
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(int_arr[i++]);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&lst, &free);
			free(int_arr);
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
	}
	free(int_arr);
	return (lst);
}

t_list	*get_stack_from_strs(int str_count, char **strs)
{
	t_list	*lst;
	t_list	*new_node;
	int		i;
	int		*content;

	lst = NULL;
	i = 0;
	while (i < str_count)
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(strs[i++]);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&lst, &free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
	}
	return (lst);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc > 1)
	{
		if (argc == 2)
			stack_a = get_stack_from_str(argv[1]);
		else
			stack_a = get_stack_from_strs(argc - 1, &argv[1]);
		if (!stack_a)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		ft_lstiter(stack_a, &print_item);
		ft_lstclear(&stack_a, &free);
		return (0);
	}
	return (0);
}
