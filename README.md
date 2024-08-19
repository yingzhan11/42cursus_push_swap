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

3- A tester for push_swap https://github.com/LeoFu9487/push_swap_tester
