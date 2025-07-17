#include "libft.h"

//transformar elementos de uma lista SEM alterar a original.
// f: função a ser aplicada no content de cada nó
// del: usada caso aconteça falha de malloc ou f

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_list;   // aponta para o inicio da nova lista
    t_list  *node;       // cada novo nó criado,  ft_lstnew();
    t_list  *ptr;       //para percorrer a lista original

    if (!lst || !f)
        return (NULL);
    node = ft_lstnew(f(lst->content)); // Cria o primeiro nó com o conteudo de lst (da original)
    if (!node)
        return (NULL);
    new_list = node; //Guarda esse primeiro nó (chama de head ou new_list)
    ptr = lst->next;
    while (ptr) //Usa um ponteiro para percorrer o resto da lista original (ex: lst = lst->next)
    {
        node = ft_lstnew(f(ptr->content)); //cria um novo no com o resultado
        if (!node)                          //locacao do no der falha, limpa tudo (para nao ter memoria vazando)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, node); //Adiciona esse novo nó ao final da nova lista
        ptr = ptr->next; //avança o ponteiro para o próximo nó da lista original
    }
    return (new_list);
}

