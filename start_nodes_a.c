/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_nodes_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:56:20 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/28 15:48:34 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
	void assing_index(node_stack **stack)
	{
	int average;
	int i;
	node_stack *tmp_stack;
	if (!stack || !*stack)
		return;
	tmp_stack = *stack;
	i = 0;
	average = stack_len(*stack) / 2;
	while(tmp_stack)
	{
		tmp_stack->index = i;
		if(i <= average)
			tmp_stack->media_moves = true;
		else
			tmp_stack->media_moves = false;
		i++;
		tmp_stack = tmp_stack->next;
	}
	}
	static void assing_target_a(node_stack **a, node_stack **b)
	{
	node_stack *tmp_a;
	node_stack *tmp_b;
	node_stack *target_node;
	long best;
	if(b == NULL || *b == NULL)
		return ;
	tmp_b = *b;
    while (tmp_b)
    {
        tmp_a = *a;
        best = LONG_MAX;
        target_node = NULL;
        while (tmp_a)
        {
            if (tmp_a->value > tmp_b->value && tmp_a->value < best)
            {
                best = tmp_a->value;
                target_node = tmp_a;
            }
            tmp_a = tmp_a->next;
        }
        if (!target_node)
            target_node = find_min(*a); // Si no hay un nodo mayor, asigna el más pequeño
        tmp_b->target_node = target_node;
        tmp_b = tmp_b->next;
    }
	}

	static void cost_analysis(node_stack *a,node_stack *b)
	{
	int len_a;
	int len_b;
	node_stack *tmp_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	tmp_b = b;
	while (tmp_b)
	{
		if((tmp_b)->media_moves)
			(tmp_b)->move_price = (tmp_b)->index;
		else
			(tmp_b)->move_price = len_a - (tmp_b)->index;
		if((tmp_b)->target_node->media_moves)
			(tmp_b)->move_price += (tmp_b)->target_node->index;
		else
			(tmp_b)->move_price += len_b - (tmp_b)->target_node->index;
		tmp_b = (tmp_b)->next;
	}
	}

	void assing_cheap(node_stack **stack)
	{
	int cheap;
	node_stack *node_cheap;
	node_stack *tmp;

	if(!stack || !*stack)
		return ;
	cheap = INT_MAX;
	node_cheap = NULL;
	tmp = *stack;
	while (tmp)
	{
		tmp->cheap = false;
		tmp = tmp ->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if((tmp)->move_price < cheap)
		{
			cheap = (tmp)->move_price;
			node_cheap = tmp;
		}
		tmp = (tmp)->next;
	}
	if (node_cheap)
		node_cheap->cheap = true;
	}


	void start_nodes(node_stack **a, node_stack **b)
	{
	if(!*b)
		return ;
	assing_index(a);
	assing_index(b);
	assing_target_a(a,b);
	cost_analysis(*a,*b);
	assing_cheap(b); 
	}