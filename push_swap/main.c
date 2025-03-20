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
    node_stack    *a;
    node_stack    *b;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        if (!av || !av[0]) // Verifica si ft_split falló o devolvió un array vacío
            error_and_free(&a, av, true);
    }
    stack_start(&a, av + (ac == 2 ? 0 : 1), ac == 2);
    if (a && !is_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a);
        if (stack_len(a) == 3)
            sort_three(&a);
        else
            sort(&a, &b);
    }
    if (ac == 2)
        free_av(av); // Libera la memoria asignada por ft_split
    return (0);
}