/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:13:56 by ctaboada          #+#    #+#             */
/*   Updated: 2025/05/01 12:15:53 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void sort_three(node_stack **a)
{
	node_stack *bigger;
	if (is_sorted(*a))
		return ;
	bigger = find_bigger(*a);
	if(bigger == *a)
		ra(a);
	else if((*a)->next == bigger)
		rra(a);
	if((*a)->value > (*a)->next->value)
		sa(a);
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
void sort_small(node_stack **a,node_stack **b)
{
	int stack_size;
	stack_size = stack_len(*a);
	assing_index(a);
	while(stack_size > 3)
	{
		min_on_top(a);
		pb(b,a);
		stack_size--;
	}
	sort_three(a);
	while (*b)
		pa(a,b);
}