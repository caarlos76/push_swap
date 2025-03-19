/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:13:56 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:38:33 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void sort_three(node_stack **a)
{
	node_stack *bigger;
	
	bigger = find_bigger(*a);
	if(bigger == *a)
		ra(a);
	else if((*a)->next == bigger)
		rra(a);	
	if((*a)->value > (*a)->next->value)
		sa(a);
}