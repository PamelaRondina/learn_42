#include "libft.h"

#include "libft.h"

// adicionar um nó no fim da lista
//O primeiro argumento é a lista onde você vai adicionar, 
//e o segundo é o novo nó:
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	back->next = new;
}
/*
static void del(void *ptr)
{
	free(ptr);
}

int main (int argc, char **argv)
{
	t_list *list;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *ptr;

	list = NULL;

	node1 = ft_lstnew(strdup("Oi, "));
	node2 = ft_lstnew(strdup("tudo "));
	node3 = ft_lstnew(strdup("bem?"));

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	ptr = list;
	while (ptr)
	{
		printf("%s", (char *)ptr->content);
		ptr = ptr->next;
	}
	ft_lstclear(&list, del);
	
	return (0);
}*/