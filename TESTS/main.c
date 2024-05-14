#include "include/test.h"

void free_list(t_list *list)
{
	t_list *tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_list *lst_new(t_list *list, int value)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_list(list);
		exit(1);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}

void add_av(t_list *list, char **av, int ac)
{
	int value;
	int i;

	i = 1;
	while (i < ac)
	{
		value = atoi(av[i]);
		ft_lstadd_back(&list, lst_new(list, value));
		i++;
	}
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

int main(int ac, char **av)
{
	t_list list;
	t_list *tmp;

	list.value = 0;
	list.next = NULL;
	if (ac < 2)
	{
		printf("Error\n");
		return (0);
	}
	add_av(&list, av, ac);
	tmp = &list;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	free_list(&list);
	return (0);

}