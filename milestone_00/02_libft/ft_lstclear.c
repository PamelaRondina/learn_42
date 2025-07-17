#include "libft.h"

// limpar a lista inteira de nós
void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *start_list; //recebe um ponteiro para acessar o inicio da lista
    t_list *temp;       //ponteiro temporario para acessar a proxima lista(no)

	if (!*lst)
        return ;

    start_list = *lst;

    while (start_list) //enquanto nao tiver nó vazio
    {
        temp = start_list->next;            //uma variavel temporaria para acessar a proxima lista
        ft_lstdelone(start_list, del);      // deletando
        start_list = temp;                  //devolvendo a 
    }
    *lst = NULL;
}
