/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:45 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:44:51 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
static void rotate(node_stack **stack)
{
	node_stack *last;
	if(*stack == NULL | (*stack)->next == NULL)
		return ;
	last = last_node(*stack);
	last->next = *stack;
	stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}
void ra(node_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}
void rb(node_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}
void rr(node_stack **a,node_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}