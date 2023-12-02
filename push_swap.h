/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:20:47 by tcharuel          #+#    #+#             */
/*   Updated: 2023/12/02 16:47:00 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MOVE_SA 1
# define MOVE_SB 2
# define MOVE_SS 3
# define MOVE_PA 4
# define MOVE_PB 5
# define MOVE_RA 6
# define MOVE_RB 7
# define MOVE_RR 8
# define MOVE_RRA 9
# define MOVE_RRB 10
# define MOVE_RRR 11

# include "libft/libft.h"
# include <stdbool.h>

typedef int				t_move;

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

t_stack_node			*get_stack_from_args(int argc, char **argv);

bool					is_str_numeric(char *str);
bool					stack_has_duplicates(t_stack_node *stack);

t_stack_node			*get_last_node(t_stack_node *stack);
int						prepend_to_stack(t_stack_node **stack, int number);
int						append_to_stack(t_stack_node **stack, int number);
int						get_stack_length(t_stack_node *stack);
void					free_stack(t_stack_node *stack);

void					display_stacks(t_stack_node *stack_a,
							t_stack_node *stack_b);

bool					is_stack_sorted(t_stack_node *stack_a);
void					sort_stack(t_stack_node **stack);

void					do_move(t_move move, t_stack_node **stack_a,
							t_stack_node **stack_b);

#endif