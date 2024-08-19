TODO malloc fail need to free in addnode func

static int i = 0;

i++;
	if (i == 5)
	{
		free(node);
		node = NULL;
	}

 static int	add_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;
	static int i = 0;

	if (stack == NULL)
		return (-1);
	node = malloc(sizeof(t_stack));
	i++;
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
