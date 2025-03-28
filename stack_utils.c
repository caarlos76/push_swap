/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:29:53 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/25 15:05:41 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

//nodos
node_stack	*f_last_node(node_stack *first)
{
	if (first == NULL)
		return NULL;
	while (first->next)
		first = first->next;
	return (first);
}
void	insert_node(node_stack **a,int num)
{
	node_stack	*node;
	node_stack	*last_node;
	
	if (a == NULL)
	{
		error_and_free(a,NULL,false);
		return ;
	}
	node = malloc(sizeof(node_stack));
	if (node == NULL)
	{
		error_and_free(a,NULL,false);
		return ;
	}
	node->value = num;
	node->next = NULL;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = f_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}
// ordenacion de nodos
// si el stack a esta ordenado me devuelve true, sino me devuelve false
bool is_sorted(node_stack *a)
{
	if(!a)
		return (true);
	while(a->next)
	{
		if(a->value > a->next->value)
		{
		return false;
		}
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
	if(!first)
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
		return NULL;
	max = LONG_MIN;
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
node_stack *find_min(node_stack *stack)
{
	long min;
	node_stack *node_min;

	if(!stack)
		return NULL;
	min = LONG_MAX;
	node_min = NULL;
	while(stack)
	{
		if(stack->value < min)
		{
			min = stack->value;
			node_min = stack;
		}
		stack = stack->next;
	}
	return(node_min);
}