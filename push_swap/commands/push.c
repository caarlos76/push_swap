/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:17:44 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:44:00 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
static void push(node_stack **dst, node_stack **src)
{
	node_stack *p_node;
	if(!*src)
		return ;
	p_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->next = NULL;
	if(!*dst)
	{
		*dst = p_node;
		p_node->next = NULL;
	}
	else
	{
		p_node->next = *dst;
		p_node->next->prev = p_node;
		p_node->next = NULL; 
	}
}
void	pa(node_stack **a,node_stack **b)
{
	push(a,b);
	ft_printf("pa\n");
}
void	pb(node_stack **b,node_stack **a)
{
	push(b,a);
	ft_printf("pb\n");
}