#include <stdio.h>
#include <stdlib.h>
#include "../include/container.h"
#include "../include/static_operations.h"
#include "../include/dynamic_operations.h"

int main(int argc, char *argv[])
{
    LinkedList *lista = buildLinkedList();

    insere_livro(lista, "Game Development: Using Unity and C#", "Millington", 2013, 43);  
    insere_livro(lista, "Game Coding Complete", "McShaffry", 2012, 32);  
    insere_livro(lista, "Game Development Essentials: An Introduction", "Novak", 2011, 42);  
    insere_livro(lista, "Prolog Programming for Artificial Intelligence", "Bratko", 2011, 31);  
    insere_livro(lista, "Beginning C++ Through Game Programming", "Dawson", 2010, 54);  
    insere_livro(lista, "Fundamentals of Database Systems", "Elmasri", 2010, 46);  
    insere_livro(lista, "Software Engineering: Theory and Practice", "Pfleeger", 2009, 28);  
    insere_livro(lista, "Introduction to Algorithms", "Cormen", 2009, 31);  
    insere_livro(lista, "Artificial Intelligence: A Modern Approach", "Russell and Norvig", 2009, 45);  
    
    quantidade_livros(lista);
    livros_ano(lista, 2010);
    livros_ano_rec(lista, 2010);

    printf("\n\nAntes\n\n");
    displayList(lista);

    printf("\n\nDepois\n\n");
    separa_ano(lista, 2009);
    displayList(lista);

    deleteLinkedList(lista);

    return 0;  
}