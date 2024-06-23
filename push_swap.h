#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
#include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

typedef struct node
{
    unsigned int original_value; //número real que é para ser sorted
    int indice_objetivo; //valor do index do valor sorted, ou seja, 1º, 2º, 3º, ou 4º, etc  
    struct node *next;
} node;

int     ft_atoi(const char *str);
void 	stack_innit(node **top, int original_value, int indice_objetivo);
void 	push(node **fonte, node **destino);
void 	rotate(node **top);
void 	reverse_rotate(node **top);
void 	swap(node **top);
void 	comparasion(node **stackA, node **stackB);
void 	print_stack(node *top);
int		ft_printf(const char *str, ...);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_conv(char *str, int i, va_list args);
char	*ft_strchr(const char *str, int c);
int numero_nodes(node **stackA);

#endif 