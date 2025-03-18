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
// funtcion split
char	**ft_split(const char *s, char c);
//stack funtcion
void	stack_start(node_stack **a,char **str, bool control);
void	insert_node(node_stack **a,int num);
// errors and free
void	error_and_free(node_stack **a, char **av, bool control);
int		error_s(char *av);
int		error_rep(node_stack *a,int num);
void	free_stack(node_stack **a);
void	free_av(char **av);
//ordenacion de nodos
bool		is_sorted(node_stack *a);
int			stack_len(node_stack *a);
node_stack	*last_node(node_stack *first);
node_stack	*find_bigger(node_stack *stack);

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



#endif