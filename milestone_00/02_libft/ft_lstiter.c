#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
static void del(void *ptr)
{
	free(ptr);
}

static void	ft_toupper_struct(void *str)
{
	char *c = (char *)str;
	int i;

	i = 0;
	while (c[i])
	{
		c[i] = ft_toupper(c[i]);
		i++;
	}
}

int main (int argc, char **argv)
{
	t_list *list;
	t_list *node1;
	t_list *node2;
	t_list *ptr;

	list = NULL;

	node1 = ft_lstnew(strdup("Oi, "));
	node2 = ft_lstnew(strdup("tudo bem?"));

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstiter(list, ft_toupper_struct);
	ptr = list;
	while (ptr)
	{
		printf("%s", (char *)ptr->content);
		ptr = ptr->next;
	}
	ft_lstclear(&list, del);
	
	return (0);
}*/