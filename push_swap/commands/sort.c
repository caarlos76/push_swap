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
    printf("antes sort three\n");
    sort_three(a);
    printf("pasa sort three\n");
    while(*b)
    {
        ft_printf("entra en b");
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
}