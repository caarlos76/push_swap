/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:01:22 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 12:38:06 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/push_swap.h"

int main(int ac, char **av)
{
	node_stack	*a;
	node_stack	*b;
	
	a = NULL;
	b = NULL;
	if (ac == 1 || (av == 2 && av[1][0]))
		return (1);
	if (av == 2)
		av = ft_split(av[1],' ');
	stack_start(a,av + 1,ac == 2);
	// hacemos un if si stack esta ordenado o no
	// si esta ordenado no hacemos nada
	// si no esta ordenado hacemos el algoritmo
	if(!is_sorted(a))
	{
		if(stack_len(a) == 2)
			sa(a);
		if(stack_len(a) == 3)
			sort_three(a);
		
	}
}