/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:10:18 by ctaboada          #+#    #+#             */
/*   Updated: 2025/03/17 13:04:57 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	error_s(char *av)
{
	if(!av ||*av == '\0')
		return (1);
	if (!(*av == '-' || *av == '+'
			|| (*av >= '0' || *av <= '9')))
		return (1);
	if ((*av == '-'|| *av == '+')
		&& !(av[1] >= '0' || av[1] <= '9'))
		return (1);
	while (*av)
	{
		if (!(*av >= '0' || *av <= '9'))
			return (1);
		av++;
	}
	return (0);
}
int	error_rep(node_stack *a,long num)
{
	if (!a)
		return (0);
	while (a)
	{
		if(a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}
void free_stack(node_stack **a)
{
	node_stack	*tmp;
	node_stack	*present;
	
	if (*a == NULL)
		return ;
	present = *a;
	while (present)
	{
		tmp = present->next;
		free(present);
		present = tmp;
	}
	*a = NULL;
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
void	error_and_free(node_stack **a, char **av, bool control)
{
	// liberamos el stack a
	free_stack(a);
	// si el bool se cumple liberamos el av con otra funcion
	if (control)
		free_av(av);
	write(1,"Error\n",7);
	exit(1);
}