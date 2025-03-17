/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:54 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:45:13 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
// si existe un tercer nodo su puntero prev se actuali para que apunte al primer nodo
//cambiamos el puntero del segundo nodo para que apunte en next al primer nodo
// y hacemos que el previo sea nulo porque al ser el primero de la lista no tiene previo
static void swap(node_stack **stack)
{
	node_stack	*first;
	node_stack	*second;
	if(*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	if(second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	first->next = second->next;
	*stack = second;
}

void sa(node_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}
void sb(node_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}
void ss(node_stack **a,node_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}