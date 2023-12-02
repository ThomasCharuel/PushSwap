/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:20:47 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 12:17:22 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

t_stack_node			*get_stack_from_args(int argc, char **argv);

void					display_stack(t_stack_node *stack);
int						append_to_stack(t_stack_node **stack, int number);
void					free_stack(t_stack_node *stack);

#endif