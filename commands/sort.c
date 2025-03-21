/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:28:47 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/21 13:28:35 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void sort(node_stack **a,node_stack **b)
{
	int num = stack_len(*a);
	while (num > 3)
	{
		if ((*a)->value == find_min(*a)->value)
			ra(a);
		else
			pb(b, a);
		num--;
	}
	sort_three(a);
	while(*b)
	{
		start_nodes_a(a,b);
		ft_printf("sale de a");
		node_stack *cheapest = *a;
		while(cheapest && !cheapest->cheap)
			cheapest = cheapest->next;
		while(*a != cheapest)
		{
			ft_printf("Después de ra: Nodo superior en a: %d\n", (*a)->value);
			if(cheapest->media_moves)
				ra(a);
			else
				rra(a);
		}
		pa(a,b);
	}
	while(!is_sorted(*a))
	{
		
		if((*a)->media_moves)
			ra(a);
		else
			rra(a);
	}
    /*
    int len_a;
    
    len_a = stack_len(a);
    if(len_a-- > 3 && !is_sorted(*a))
        pb(b,a);
    if(len_a-- > 3 && !is_sorted(*a))
        pb(b,a);
    while(len_a-- > 3 && !is_sorted(*a))
    {
        start_nodes_a(*a,*b);
        move_a_to_b(a,b);
    }
    */
   /*
   
void move_to_top(node_stack **stack, node_stack *target)
{
    int position = 0;
    int len = stack_len(*stack);
    node_stack *tmp = *stack;

    while (tmp && tmp != target)
    {
        position++;
        tmp = tmp->next;
    }

    if (position <= len / 2)
    {
        while (*stack != target)
            ra(stack); // Rotar hacia arriba
    }
    else
    {
        while (*stack != target)
            rra(stack); // Rotar hacia abajo
    }
} 
   */

   /* 
 void sort(node_stack **a, node_stack **b)
{
    int len = stack_len(*a);

    // Paso 1: Mover elementos de A a B, dejando solo 3 elementos en A
    while (len > 3)
    {
        if (is_one_of_three_smallest(*a))
            ra(a); // Si el nodo superior es uno de los tres más pequeños, rota A
        else
            pb(b, a); // Si no, mueve el nodo superior de A a B
        len--;
    }

    // Paso 2: Ordenar los 3 elementos restantes en A
    sort_three(a);

    // Paso 3: Mover elementos de B de vuelta a A
    while (*b)
    {
        // Calcular nodos objetivo y costos
        calculate_targets_and_costs(a, b);

        // Encontrar el nodo más barato en B
        node_stack *cheapest = find_cheapest_node(*b);

        // Mover el nodo más barato a la parte superior de B
        move_to_top(b, cheapest);

        // Mover el nodo superior de B a A
        pa(a, b);
    }

    // Paso 4: Asegurarse de que A esté completamente ordenado
    while (!is_sorted(*a))
    {
        if ((*a)->media_moves)
            ra(a); // Rotar hacia arriba
        else
            rra(a); // Rotar hacia abajo
    }
}  
   */
}