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
    node_stack *tmp_stack;
    node_stack *current;
    int index;
    tmp_stack = *stack;
    while (tmp_stack)
    {
        index = 0;
        current = *stack;
        while (current)
        {
            if (current->value < tmp_stack->value)
                index++;
            current = current->next;
        }
        tmp_stack->index = index; // Asignar el índice calculado
        tmp_stack = tmp_stack->next;
    }
}
void start_nodes(node_stack **a, node_stack **b)
{
	if(!*b)
		return ;
	assing_index(a);
	assing_index(b);
}