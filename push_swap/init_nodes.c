#include "./includes/push_swap.h"
static void assing_index(node_stack **a)
{
    int average;
    int i;

    i = 0;
    average = stack_len(*a) / 2;
    while(*a)
    {
        (*a)->index = i;
        if(i < average)
            (*a)->media_moves = true;
        else
            (*a)->media_moves = false;
        i++;
        *a = (*a)->next;
    }
}
static void assing_target(node_stack **a, node_stack **b)
{
    node_stack *tmp_b;
    node_stack *target_node;
    int best;
    while(*a)
    {
        tmp_b = *b;
        best = INT_MAX;
        while(tmp_b)
        {
            if(tmp_b->value < (*a)->value && tmp_b > best)
            {
                best = tmp_b->value;
                target_node = tmp_b;
            }
            tmp_b = tmp_b->next;
        }
        if(!target_node)
            target_node = find_bigger(*b);
        (*a)->target_node = target_node;
    }
}

static void cost_analysis(node_stack **a,node_stack **b)
{
    int len_a;
    int len_b;

    len_a = stack_len(*a);
    len_b = stack_len(*b);
    while (*a)
    {
        if((*a)->media_moves)
            (*a)->move_price = (*a)->index;
        else
            (*a)->move_price = len_a - (*a)->index;
        if((*a)->target_node->media_moves)
            (*a)->move_price += (*a)->target_node->index;
        else
            (*a)->move_price += len_b - (*a)->target_node->index;
        *a = (*a)->next;
    }
}

static void assing_cheap(node_stack **stack)
{
    int cheap;
    node_stack *node_cheap;
    if(!stack)
        return ;
    cheap = INT_MAX;
    while (*stack)
    {
        if((*stack)->move_price < cheap)
        {
            cheap = (*stack)->move_price;
            node_cheap = *stack;
        }
        *stack = (*stack)->next;
    }
    
}


void start_nodes_a(node_stack **a, node_stack **b)
{
    assing_index(a);
    assing_index(b);
    assing_target(a,b);
    cost_analysis(a,b);
    assing_cheap(a); 
}