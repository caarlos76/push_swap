#include "includes/push_swap.h"

void sort(node_stack **a,node_stack **b)
{
    int len_a;
    
    len_a = stack_len(a);
    if(len_a-- > 3 && !is_sorted(*a))
        pb(b,a);
    if(len_a-- > 3 && !is_sorted(*a))
        pb(b,a);
    while(len_a-- > 3 && !is_sorted(*a))
    {
        init_nodes_a(*a,*b);
    }
}