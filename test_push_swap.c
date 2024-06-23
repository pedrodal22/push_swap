#include "push_swap.h"

/*
XXXXX 1. - fazer com que a ordem dos index estejam corretos
XXXXX 2, - Fazer com que funcione com argc, argv 
4, - Fazer com que funcione com linked lists 
5, - Fazer as funções e testa-las
6, - Fazer as condições bitwise (não tenho que passar o número para binário, pois caso contrário iria perder os zeros que tenho à esquerda do número binário em si. Devo por isso usar bitwise operators sem converter o número para binário manualmente. )
*/

void print_stack(node *top) {
    int i = 1;
    node *current = top;
    while (current != NULL) {
        printf("Original %i: %d, Indice: %d\n", i, current->original_value, current->indice_objetivo);
        current = current->next;
        i++;
    }
    printf("-----\n\n");
}

int main(int argc, char *argv[])
{
    int count = argc - 1;
    int *array = (int *)malloc(count * sizeof(int));
    int array_indices[count];
    int copy[count];
    node *stackA = NULL;
    node *stackB = NULL;
    int temp;
    int i;
    int a;

    i = 0;
    a = 0;

    //cria uma cópia da array original
    while(i < count)
    {
        array[i] = ft_atoi(argv[i + 1]);
        copy[i] = ft_atoi(argv[i +1]);
        i++;
    }

    //bubble sort
    i = 0;
    while (i < count)
    {
        while(a < count - i - 1)
        {
             if(copy[a] > copy[a + 1])
            {
                temp = copy[a];
                copy[a] = copy[a + 1];
                copy[a + 1] = temp;
            }
            a++;
        }
        a = 0;
        i++;
    }

    i = 0;
    //coloca os indexs ordenados na array original
    while(i < count)
    {
        a = 0;
        while(a < count)
        {
            if(array[i] == copy[a])
            {
                array_indices[i] = a;
                break;
            }
            a++;
        }
        i++;
    }

    i = 0;

    while(i < count)
    {
        stack_innit(&stackA, array[i], array_indices[i]);
        i++;
    }

    printf("StackA: \n");
    print_stack(stackA);
    printf("StackB: \n");
    print_stack(stackB);

    comparasion(&stackA, &stackB);
    printf("\n");

    printf("StackA: \n");
    print_stack(stackA);
    printf("StackB: \n");
    print_stack(stackB);

 /*    printf("\n");
    push(&stackB, &stackA);
    printf("\n");

    printf("StackA: \n");
    print_stack(stackA);
    printf("StackB: \n");
    print_stack(stackB); */
/*     
    i = 0;
    a = 0;

    //print valores iniciais
    printf("\nValores reais (array): \n");
    while(i < count)
    {
        printf("%i", array[i]);
        printf("\n");
        i++;
    }

    i = 0;
    //print ordenados
    printf("\nValores índices (copy): \n");
    while(i < count)
    {
        printf("%i", copy[i]);
        printf("\n");
        i++;
    }

    i = 0;
    //print resultado final
    printf("\nValores índices: \n");
    while(i < count)
    {
        printf("%i", array_two[i]);
        printf("\n");
        i++;
    } */


}

//void push(node **top, int original_value, int indice_objetivo)