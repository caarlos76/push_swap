#include "./includes/push_swap.h"
void assing_index(node_stack **stack)
{
    int average;
    int i;
    node_stack *tmp_stack;
    if (!stack || !*stack)
        return;
    tmp_stack = *stack;
    i = 0;
    average = stack_len(*stack) / 2;
    while(tmp_stack)
    {
        (tmp_stack)->index = i;
        if(i < average)
            (tmp_stack)->media_moves = true;
        else
            (tmp_stack)->media_moves = false;
        i++;
        tmp_stack = (tmp_stack)->next;
    }
}
static void assing_target_a(node_stack **a, node_stack **b)
{
    node_stack *tmp_b;
    node_stack *target_node;
    int best;
    while(*a)
    {
        tmp_b = *b;
        best = INT_MAX;
        target_node= NULL;
        while(tmp_b)
        {
            if(tmp_b->value < (*a)->value && tmp_b->value > best)
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
    node_stack *tmp_a;

    len_a = stack_len(*a);
    len_b = stack_len(*b);
    tmp_a = *a;
    while (tmp_a)
    {
        if((tmp_a)->media_moves)
            (tmp_a)->move_price = (tmp_a)->index;
        else
            (tmp_a)->move_price = len_a - (tmp_a)->index;
        if((tmp_a)->target_node->media_moves)
            (tmp_a)->move_price += (tmp_a)->target_node->index;
        else
            (tmp_a)->move_price += len_b - (tmp_a)->target_node->index;
        tmp_a = (tmp_a)->next;
    }
}

static void assing_cheap(node_stack **stack)
{
    int cheap;
    node_stack *node_cheap;
    node_stack *tmp;

    if(!stack || !*stack)
        return ;
    cheap = INT_MAX;
    node_cheap = NULL;
    tmp = *stack;
    while (tmp)
    {
        if((tmp)->move_price < cheap)
        {
            cheap = (tmp)->move_price;
            node_cheap = tmp;
        }
        tmp = (tmp)->next;
    }
    if (node_cheap)
        node_cheap->cheap = true;
}


void start_nodes_a(node_stack **a, node_stack **b)
{
    assing_index(a);
    assing_index(b);
    assing_target_a(a,b);
    cost_analysis(a,b);
    assing_cheap(a); 
}