
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list)); //persista, que continue na memoria ate o free.
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return(new_node);
}
/*
int main(int argc, char **argv)
{
	t_list *node;

	if (argc < 2)
	{
		printf("%s", argv[0]);
		return (1);
	}

	node = ft_lstnew(argv[1]);

	if (node)
	{
		printf("Conteudo guardado no nó: %s\n", (char *)node->content);
		printf("O proximo nó é: %p (deve ser NULL)\n", node->next);
	}
	else
		printf("ERRO!");
	
	free(node);
	return (0);
}*/