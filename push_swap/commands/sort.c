#include "../includes/push_swap.h"

void sort(node_stack **a,node_stack **b)
{
    while(stack_len(*a) > 3)
    {
        if((*a)->value == find_min(*a)->value)
            ra(a);
        else
            pb(a,b);
    }
    sort_three(a);
    while(*b)
    {
        start_nodes_a(a,b);
        node_stack *cheapest = *a;
        while(cheapest && !cheapest->cheap)
            cheapest = cheapest->next;
        while(*a != cheapest)
        {
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