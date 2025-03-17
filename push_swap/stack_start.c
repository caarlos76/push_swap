/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:50 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:38:54 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// a es la pila, str es el argv y control es argc == 2
void stack_start(node_stack **a,char **av, bool control)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_s(av[i]))
			error_and_free(a,av,control);
		num = ft_atoi(av);
		if (num <= INT_MIN || num >= INT_MAX)
			error_and_free(a,av,control);
		if(error_rep(*a,num))
			error_and_free(a,av,control);
		insert_node(*a,num);
		i++;
	}
	if (control)
		error_and_free(a,av,control);
}
