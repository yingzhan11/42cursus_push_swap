# Some useful tips

1- I use greedy algorithm to do this project, and here is a tutorial vedio https://www.youtube.com/watch?v=OaG81sDEpVk&t=201s. I modify this tutorial's logic, he push all nodes to stackB, then when he push node back to stackA, he sorts the node. In my code, I push nodes to stackB and sort it in a descending order, then push them back to stackA, this way can save about 100-200 steps for 500 numbers.

2- A malloc and free which is easy to be ingnored in this project is when add node to linked list. If the malloc for one node is fail, we usually just ```return ;``` but if the failed node is not the first one, we already create stackA with some nodes and has a slipt str that also need to be freed. This is not happen often, so you want to test it, you can add few lines code inside add_node func to set a node equal to NULL manually, like:

```
static int	add_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;
	static int i = 0; //a static i to count node

	if (stack == NULL)
		return (-1);
	node = malloc(sizeof(t_stack));
	i++;
	//set the sixth node to NULL
	if (i == 5)
	{
		free(node);
		node = NULL;
	}
	if (node == NULL)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
	return (0);
}
```

3- A tester for push_swap https://github.com/LeoFu9487/push_swap_tester. If test for 500 numbers for 500 times, my code would have 1 time use more than 5500 steps, but average steps are always less than 5500, so it is ok for evaluation requirement.

4- This code can also be optimized. As for the node position is just 1 above the middle, and target postion is 1 position below median, my algorithm would rotate src_stack and rev_rotate the dst_stack, so the steps is ```current postion + (stack_len - target_postion)```, but actually, rev_rotate both may use less steps. And also all nodes near median may have the same problem. So for those nodes within the range of half stack up or below medan (1/4stack to 3/4stack, so the src_stack will be divided into 4 part, 0-1/4stack, 1/4-median, median-3/4stack, 3/4-end of stack), it need to compare my current algorithm and rotate both(or rev_rotate both) to get the less steps. This optimization can save about 100-200 steps. So that move than 5500 steps for 500 numbers will not happen. (This way to divided the stack into 4 part is a little bit similar to chunk sort).
