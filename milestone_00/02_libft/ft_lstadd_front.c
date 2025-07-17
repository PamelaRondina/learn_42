#include "libft.h"

// adicionar um nó no início da lista
// ponteiro para a lista original (**lst)
//um novo nó (t_list *new)

void	ft_lstadd_front(t_list **lst, t_list *new)
{
		new->next = *lst;
		*lst = new; 
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
		new = ft_lstnew(argv[i]);
		ft_lstadd_front(&list, new); //adicionado o primeiro no na lista
		i++;
	}

	ptr = list; 

	while(ptr)
	{
		printf("%s ", (char *)ptr->content);
		ptr = ptr->next;
	}
	list = ptr;
	
	ft_lstclear(&list, free);	
	
	return (0);
}
*/
