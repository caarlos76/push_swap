#include "./includes/push_swap.h"

static void assing_target_b(node_stack **a,node_stack **b)
{
    node_stack *tmp_a;
    node_stack *target_node;
    int best;
    while(*b)
    {
        tmp_a = *a;
        best = INT_MAX;
        while (tmp_a)
        {
            if(tmp_a->value > (*b)->value && tmp_a->index < best)
            {
                best = tmp_a->value;
                target_node = tmp_a;
            }
            tmp_a = tmp_a->next;
        }
        if(best == INT_MAX)
            (*b)->target_node = find_min(*a);
        else
            (*b)->target_node = target_node;
        *b = (*b)->next;
    }
}


void start_nodes_b(node_stack **a, node_stack **b)
{
    assing_index(a);
    assing_index(b);
    assing_target_b(a,b);
}
