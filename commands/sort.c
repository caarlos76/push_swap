/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:28:47 by ctaboada          #+#    #+#             */
/*   Updated: 2025/04/01 16:20:21 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static int size_chunk(int size)
{
	if(size <= 100)
		return 20; // para 100 5 chunks de 20
	else
		return 45; // para 500 11 chunks de 45
}
static void push_chunk_b(node_stack **a,node_stack **b,int start, int end)
{
	int pushed;
	int size;

	pushed = 0;
	size = stack_len(*a);
	while (pushed < (end - start + 1) && size > 0)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
		size--;
	}
}
int get_max_position_index(node_stack **stack)
{
	node_stack *tmp = *stack;
	int max_index = tmp->index;
	int max_pos = 0;
	int current_pos = 0;
	
	while(tmp)
	{
		if(tmp->index > max_index)
		{
			max_index = tmp->index;
			max_pos = current_pos;
		}
		tmp = tmp->next;
		current_pos++;
	}
	return(max_pos);
}
static void move_to_top(node_stack **stack, int pos)
{
    int size;
    
    size = stack_len(*stack);
    if (pos <= size / 2) // Si la posición está en la primera mitad
    {
        while (pos > 0) // Rotamos hacia arriba
        {
            rb(stack);
            pos--;
        }
    }
    else // Si la posición está en la segunda mitad
    {
        pos = size - pos;
        while (pos > 0) // Rotamos hacia abajo
        {
            rrb(stack);
            pos--;
        }
    }
}
void sort(node_stack **a, node_stack **b)
{
	int	chunk_size;
	int size;
	int start;
	int end;
	int max_positition;
	
	size = stack_len(*a);
	chunk_size = size_chunk(size);
	start = 0;
	end = chunk_size - 1;
	
	while(start < size - 1)
	{
		push_chunk_b(a,b,start,end);
		start = end + 1;
		end = start + chunk_size - 1;
		if(end >= size - 1)
			end = size - 1;
	}
	while (*b)
	{
		max_positition = get_max_position_index(b);
		move_to_top(b,max_positition);
		pa(a,b);
	}
}