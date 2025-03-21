/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:44:21 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:44:29 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static void reverse_rotate(node_stack **stack)
{
	node_stack *last;
	if(!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
void rra(node_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}
void rrb(node_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}
void rrr(node_stack **a,node_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}