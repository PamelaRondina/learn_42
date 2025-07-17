#include "libft.h"

//deletar um único nó
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del) //nao tem nó para deletar
		return ;
	else
	{
		del(lst->content); //pode ser qualquer tipo de dado
		free(lst);
		return ;
	}
}
/*
//deleta qualquer tipo de dado
static void del(void *ptr)
{
	free(ptr);
}

int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*list;
	t_list	*ptr;

	list = NULL;

	node1 = ft_lstnew(ft_strdup("Continue a "));
	node2 = ft_lstnew(ft_strdup("Nadar!"));

	node1->next = node2;
	list = node1;

	ptr = list;
	while(list)
	{
		printf("%s", (char *)list->content);
	list = list->next;
	}
	ft_lstdelone(node2, del);
	node1->next = NULL;

	while(ptr) //Depois da função
	{
		printf("\nDepois de função: %s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
	ft_lstclear(&list, del);
	
	return (0);
}*/