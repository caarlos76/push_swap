/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:45 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/25 14:41:22 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static void rotate(node_stack **stack)
{
	node_stack *first;
	node_stack *last;
	if(!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
    *stack = first->next;       // El segundo nodo se convierte en el primero
    (*stack)->prev = NULL;      // El nuevo primer nodo no tiene anterior
    last->next = first;         // El antiguo primer nodo se convierte en el último
    first->prev = last;         // Actualiza el puntero `prev` del antiguo primer nodo
    first->next = NULL;
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