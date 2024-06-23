#include "push_swap.h"

int numero_nodes(node **stackA)
{
	int i;
	node *current;

	i = 0;
	current = *stackA;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return(i);
}

int check_order(node **stackA, int i_nodes)
{
	node *current;
	node *current_next;

	current = *stackA;
	current_next = current->next;
	while(current_next->next != NULL)
	{
		current_next = current->next;
		if(current->indice_objetivo < current_next->indice_objetivo)
		{
			current = current->next;
			current_next = current_next->next;
		}
		else
			return(1);
	}
	return (0);
}

void comparasion(node **stackA, node **stackB)
{
    unsigned int mask;
	int i_nodes;
	int i;
	node *current;
	node *last;
	int counter;

	mask = 1;
	i_nodes = numero_nodes(stackA);
	current = *stackA;
	counter = 0;

	while(mask != 0)
	{
		current = *stackA;
		i = 0;
		while(i < i_nodes)
		{
			if ((current->indice_objetivo & mask) == 0)
			{
				push(stackA, stackB);
				counter++;
				ft_printf("pa\n");
			}
			else
			{
				rotate(stackA);
				counter++;
				ft_printf("ra\n");
			}
			current = *stackA;
		/* 	printf("\n");
			printf("StackA:\n");
			print_stack(*stackA);
			printf("StackB:\n");
			print_stack(*stackB); */
			i++;
		}
		while(*stackB != NULL)
		{
			push(stackB, stackA);
			printf("pb\n");
			counter++;
		}
		mask <<= 1;
	}
	printf("\n");
	printf("%i\n", counter);
}