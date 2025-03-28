/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:28:47 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/28 16:20:21 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static void move_a_to_b(node_stack **a,node_stack **b)
{
	assing_cheap(a);
    node_stack *cheap = *a;
	while (cheap && !cheap->cheap)
		cheap = cheap->next;
	
    if (cheap)
	{
		while(*a != cheap)
		{
			if(cheap->media_moves)
				ra(a);
			else
				rra(a);
		}
		pb(b,a);
	}
}
static node_stack *find_target_node(node_stack *a, node_stack *b_node)
{
    node_stack *current = a;
    node_stack *best_target = NULL;

    while (current)
    {
        if (!best_target || (current->value > b_node->value && current->value < best_target->value))
            best_target = current;
        current = current->next;
    }

    // Si no hay un nodo mayor, devolver el menor (circularidad)
    if (!best_target)
        best_target = find_min(a);

    return best_target;
}
static void move_b_to_a(node_stack **a,node_stack **b)
{
	assing_cheap(b);
	node_stack *cheap = *b;
	while (cheap && !cheap->cheap)
		cheap = cheap->next;
	if (cheap)
	{
		while(*b != cheap)
		{
			if(cheap->media_moves)
				rb(b);
			else
				rrb(b);
		}
	}
	if(!cheap->target_node)
		cheap->target_node = find_target_node(*a,cheap);
	// rotar a para posicionar el nodo objetivo
	node_stack *target =cheap->target_node;
	if(!target)
		return ;
	while (*a != target)
	{
		if(target->media_moves)
			ra(a);
		else
			rra(a);
	}
	pa(a,b);
}

static void min_on_top(node_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if(find_min(*a)->media_moves)
			ra(a);
		else
			rra(a);
	}
	
}

void sort(node_stack **a, node_stack **b)
{
    int len_a = stack_len(*a);
	if(is_sorted(*a))
		return ;
    // Mover elementos de `a` a `b` hasta que queden 3 en `a`
    while (len_a-- > 3 && !is_sorted(*a))
    {
        start_nodes(a,b); // Inicializar nodos en `b`
        move_a_to_b(a, b); // Mover el nodo más barato de `a` a `b`
    }

    // Ordenar los 3 elementos restantes en `a`
    sort_three(a);
	
    // Mover todos los elementos de `b` de vuelta a `a`
    while (*b)
    {
        assing_cheap(b); // Inicializar nodos en `b`
        move_b_to_a(a, b); // Mover el nodo más barato de `b` a `a`
    }

    // Asegurarse de que `a` esté completamente ordenado
    assing_index(a); // Actualizar índices de los nodos
    min_on_top(a); // Asegurar que el valor mínimo esté en la parte superior
}
