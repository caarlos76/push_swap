/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:44:21 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/25 14:56:55 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static void reverse_rotate(node_stack **stack)
{
	node_stack *last;
	node_stack *second_last;
	if(!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	second_last = last->prev;
	
	second_last->next = NULL;   // El penúltimo nodo se convierte en el último
    last->prev = NULL;          // El nuevo primer nodo no tiene anterior
    last->next = *stack;        // Conecta el antiguo último nodo al principio
    (*stack)->prev = last;      // Actualiza el puntero `prev` del antiguo primer nodo
    *stack = last;    
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