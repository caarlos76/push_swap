/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:29:53 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:39:00 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

//nodos
node_stack	*f_last_node(node_stack *first)
{
	if (first == NULL)
		return;
	while (first->next)
		first = first->next;
	return (first);
}
void	insert_node(node_stack **a,int num)
{
	node_stack	*node;
	node_stack	*last_node;
	
	if (a == NULL)
		return ;
	node = malloc(sizeof(node_stack));
	if (node == NULL)
		return ;
	node->value = num;
	node->next = NULL;
	if (*a == NULL)
	{
		a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = f_last_node(a);
		last_node->next = node;
		node->prev = last_node;
	}
}
// ordenacion de nodos
// si el stack a esta ordenado me devuelve true, sino me devuelve false
bool is_sorted(node_stack *a)
{
	while(a->next)
	{
		if(a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}
int stack_len(node_stack *a)
{
	int i;

	i = 0;
	while(a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
node_stack	*last_node(node_stack *first)
{
	if(first == NULL)
		return (NULL);
	while(first->next)
		first = first->next;
	return (first);
}
node_stack	*find_bigger(node_stack *stack)
{
	long	max;
	node_stack	*node_max;

	if(!stack)
		return;
	max = LONG_MAX;
	while (stack)
	{
		if(stack->value > max)
		{
			max = stack->value;
			node_max = stack;
		}
		stack = stack->next;
	}
	return(node_max);
}