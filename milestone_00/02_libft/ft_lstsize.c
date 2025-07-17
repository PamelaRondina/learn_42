#include "libft.h"

// contar quantos nós tem na lista
int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
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
		new = ft_lstnew(strdup(argv[i])); //para deletar mais abaixo
		ft_lstadd_front(&list, new); //adicionado o primeiro no na lista
		i++;
	}

	ptr = list; 
	while(ptr)
	{
		printf("%s ", (char *)ptr->content);
		ptr = ptr->next;
	}
	printf("\n%d\n", ft_lstsize(list));

	ft_lstclear(&list, del); //deleta memoria alocada para a string criada
	
	return (0);
}
*/


 
