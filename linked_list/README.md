# Linked List

Este projeto é uma implementação de uma lista ligada em C. Ele fornece uma interface com várias operações usadas para manipular dados na lista ligada.

## Interface

### Definição do nó

```
typedef struct node
{
    int data;
    struct node *next;
}
node;
```

### Definição da Lista Ligada

```
typedef struct
{
    int length;
    node *head;
    node *tail;
}
linked_list;
```

### Funções

- `build_linked_list()`: Cria uma nova lista ligada vazia.
- `delete_list(linked_list *list)`: Deleta a lista ligada, liberando toda a memória alocada.
- `get_at(linked_list *list, int idx)`: Retorna o nó na posição especificada.
- `insert_first(linked_list *list, int data)`: Insere um novo nó no início da lista.
- `insert_last(linked_list *list, int data)`: Insere um novo nó no final da lista.
- `remove_first(linked_list *list)`: Remove o nó no início da lista.
- `remove_last(linked_list *list)`: Remove o nó no final da lista.
- `reverse_list(linked_list *list)`: Inverte a ordem dos nós na lista.
- `find(node *head, int val)`: Verifica se um valor está na lista.
- `set_at(linked_list *list, int idx, int val)`: Define o valor do nó na posição especificada.
- `remove_nodes_matching_condition(linked_list *list, remove_function function)`: Remove nós que satisfazem uma condição específica.
- `linked_list_operation_menu()`: Oferece um menu onde o usuário pode interagir em tempo real com uma lista ligada, realizando todas as operações listadas acima.

## Compilação

Para compilar o programa basta utilizar o comando: 
```
make
```
e para execução:
```
make run
```
Também é possível utilizar o comando:
```
make valgrind
```
para testar se há vazamentos de memória.

## Autor

Este código foi inteiramente desenvolvido por Arthur Andrade D'olival, estudante da Instituição IFB, cursando Bacharelado em Ciência da Computação.