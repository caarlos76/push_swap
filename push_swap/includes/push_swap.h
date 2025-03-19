/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:40:07 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:59:04 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct s_stack_node
{
	int		value;
	int		position;
	int		move_price;
	int		index;
	bool	media_moves;
	bool	cheap;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} node_stack;

//create and start a stack
void	stack_start(node_stack **a,char **str, bool control);
//inserts numbers in the stack
void	insert_node(node_stack **a,int num);
// errors and free
void	error_and_free(node_stack **a, char **av, bool control);
//Error sintax
int		error_s(char *av);
//error repetition
int		error_rep(node_stack *a,int num);
//free stack
void	free_stack(node_stack **a);
//free av
void	free_av(char **av);
//is sorted the stack?
bool		is_sorted(node_stack *a);
//stack len 
int			stack_len(node_stack *a);
//find las node
node_stack	*last_node(node_stack *first);
//find min node
node_stack	*find_min(node_stack *stack);
//find the bigger node
node_stack	*find_bigger(node_stack *stack);
//put a number to each node of the stack, and look if the node is above average
void assing_index(node_stack **stack);

//start nodes in a, to see what node is cheaper to move, and put a index to the nodes, find the object node in stack b, calculate the cost of the move
void start_nodes_a(node_stack **a, node_stack **b);
//
void start_nodes_b(node_stack **a, node_stack **b);
//commands
void	sa(node_stack **a);
void	sb(node_stack **b);
void	ss(node_stack **a,node_stack **b);
void	ra(node_stack **a);
void	rb(node_stack **b);
void	rr(node_stack **a,node_stack **b);
void	pa(node_stack **a,node_stack **b);
void	pb(node_stack **b,node_stack **a);
void	rra(node_stack **a);
void	rrb(node_stack **b);
void	rrr(node_stack **a,node_stack **b);

//sort 
void sort_three(node_stack **a);
void sort(node_stack **a, node_stack **b);

#endif