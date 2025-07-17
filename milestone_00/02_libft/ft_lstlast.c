#include "libft.h"

#include "libft.h"

//informa o conteudo do ultimo nó de uma lista encadeada
// next é NULL pois nao aponta para outra lista!

t_list	*ft_lstlast(t_list *lst)
{
	t_list *last_node;

	if (!lst)
	return (NULL);

	last_node = lst;

	while (last_node->next != NULL) //percorre ate que o next nao visualize o proximo nó
		last_node = last_node->next; //acessa o proximo next.

	return (last_node); // retorna o ultimo *next da struct
}
/*
static void del(void *ptr)
{
	free(ptr);
}

int main (int argc, char **argv)
{
	t_list *new;
	t_list *list;
	t_list *ptr;
	t_list *last;
	int i;
	
	if (argc < 2)
		{
			printf("%s\n", argv[0]);
			return (1);
		}
		
	i = 1;
	list = NULL; //variavel inicializada, sem puxar valor de lixo de memoria

	while (i < argc)
	{
		new = ft_lstnew(strdup(argv[i])); //para deletar mais abaixo
		ft_lstadd_front(&list, new); //adicionado o primeiro no na lista
		i++;
	}

	ptr = list; 
	while(ptr)
	{
		printf("%s -> ", (char *)ptr->content);
		ptr = ptr->next;
	}
	last = ft_lstlast(list);
	if (last)
		printf("\n%s : ultimo node\n", (char *)last->content);
	ft_lstclear(&list, del); //deleta memoria alocada para a string criada
	
	return (0);
}*/
