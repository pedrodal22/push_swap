#include "push_swap.h"


/* Esta função inicializa a stack A, ou seja, adiciona os valoes originais, 
assim como os repsetivos índices objetivos. Adiciona portanto os valores 
por baixo, ou seja, o primeiro valor fica na primeira posição, e os 
subseguintes ficam por baixo */
void stack_innit(node **top, int original_value, int indice_objetivo)
{
    node *newNode;
    newNode = malloc(sizeof(newNode));
    if(newNode == NULL)
        printf("Problema");
    newNode->original_value = original_value;
    newNode->indice_objetivo = indice_objetivo;
    newNode->next = NULL;

    if (*top == NULL)
        *top = newNode;
    else
    {
        // Percorre até o final da stack, até à variável next apontar para NULL
        node *current = *top;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode; // Adiciona o novo node ao final
    }
}

//esta função NÃO é para inicializar a stack.
//são adicionados ao início da stack. esta é a função push, para os comandos  pa & pb
void push(node **fonte, node **destino)
{
    node *temp;

    if(*fonte == NULL)
        return;
    temp = *fonte;
    *fonte = (*fonte)->next;
    temp->next = *destino;
    *destino = temp;
}

//função rotate
//o primeiro elemento torna-se no último. 
void rotate(node **top)
{
    node *primeiro;
    node *current;

    primeiro = *top;
    current = *top;
    if (*top == NULL || (*top)->next == NULL)
        return;

    while (current->next != NULL)
        current = current->next;

    *top = primeiro->next; //move o segundo nó (next) para o topo da stack
    current->next = primeiro; //current next, que aponta para NULL, pois é o último node, é agora o primeiro, ou seja, o primeiro node é agora o último. 
    primeiro->next = NULL; //o primeiro, que agora está no final da stack, aponta para NULL, pois está no final da stack, e é o último node. 
}

//função reverse_rotate
//o último elemento torna-se o primeiro.
void reverse_rotate(node **top)
{
    
    if (*top == NULL || (*top)->next == NULL)
        return;

    node *current;
    node *penultimo;

    current = *top;
    penultimo = NULL;
    while (current->next != NULL) {
        penultimo = current;
        current = current->next;
    }

    if (penultimo != NULL) {
        penultimo->next = NULL;
    }
    
    current->next = *top;
    *top = current;

    //current avança até ao final da stack. penultimo avança até ao penultimo node.
    //current next é igualado ao topo, ou seja, o NULL de current->next passa a ser o topo
    //o top, que é o primeiro elemento da stack, passa a ser o current, que era o último elemento da stack antes de ser adicionado o top ao inicio. 
}


//troca os dois primeiros nodes de uma stack
void swap(node **top)
{
    node *current;
    node *segundo;

    if (*top == NULL || (*top)->next == NULL)
        return;
    current = *top;
    segundo = (*top)->next;
    current->next = segundo->next; //faz com que o primeiro deixe de apontar para o segundo e passe a apontar para o terceiro
    segundo->next = current; //faz com que o segundo node aponte para o primeiro
    *top = segundo; //faz do "segundo" node o novo topo da stack
}
