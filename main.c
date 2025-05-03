/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:01:22 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/21 12:22:06 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/push_swap.h"
static void sort_stack(node_stack *a, node_stack *b)
{
    if (stack_len(a) == 2)
        sa(&a);
    else if (stack_len(a) >= 3 &&  stack_len(a) <= 5)
        sort_small(&a,&b);
    else
        sort(&a, &b); // Llama a la nueva función de ordenación
}
int main(int ac, char **av)
{
	node_stack	*a;
	node_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putendl_fd("Error",2);
		return (1);
	}
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av || !av[0]) // Verifica si ft_split falló o devolvió un array vacío
			error_and_free(&a, av, true);
		stack_start(&a, av, ac == 2);
	}
	else
		stack_start(&a, av + 1, ac == 2);
	if (a && !is_sorted(a))
	{
		assing_index(&a);
		sort_stack(a,b);
	}
	return (0);
}