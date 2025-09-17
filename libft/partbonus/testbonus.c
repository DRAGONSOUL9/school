#include "libft.h"

void	ft_freenode(void *content)
{
	if (!content)
		return ;
	free(content);
}

void	ft_putlst(t_list *node)
{
	if (!node)
		return ;
	while (node)
	{
		ft_putstr_fd(node->content,1);
		if ((node->next))
		{
			ft_putstr_fd(" -> ",1);
			node = node->next;
		}
		else
			break ;
	}
	write (1, "\n", 1);
}

void	test_partbonus(void)
{
	t_list *test = NULL;

	//ft_lstnew
	ft_putstr_fd("\n---------------ft_lstnew------------\n",1);
	test = ft_lstnew("this is a test");
	ft_putendl_fd(test->content, 1);
	if (test->next == NULL)
		ft_putendl_fd("next is NULL",1);
	else
		ft_putendl_fd("next is not NULL",1);

	//void    ft_lstadd_front(t_list **lst, t_list *new)
	ft_putstr_fd("\n---------------ft_lstadd_front------------\n",1);
	test = NULL;
	int     i = 0;
        char	*str;
        while (i < 15)
        {
                str = ft_strdup(ft_itoa(i));
                ft_lstadd_front(&test,ft_lstnew(str));
		i++;
        }
	ft_putlst(test);

	//int ft_lstsize(t_list *lst)
	ft_putstr_fd("\n---------------ft_lstsize------------\n",1);
	ft_putnbr_fd(ft_lstsize(test),1);
	write (1, "\n", 1);

	//ft_lstlast
	ft_putstr_fd("\n---------------ft_lstlast------------\n",1);
	ft_putstr_fd("last element in the struct is : ",1);
	t_list *test3 = ft_lstlast(test);
	ft_putstr_fd((test3->content), 1);
	write (1, "\n", 1);

	//ft_lstadd_back
	ft_putstr_fd("\n---------------ft_lstadd_back------------\n",1);
	t_list *test4 = NULL;
        i = 0;
        while (i < 15)
        {
                str = ft_strdup(ft_itoa(i));
                ft_lstadd_back(&test4,ft_lstnew(str));
                i++;
        }
	ft_putlst(test4);
	ft_putstr_fd("\nthis is a test to see if i can concatenate two nodes test and test4\n",1);
	ft_lstadd_back(&test4,test);
	ft_putlst(test4);

	//ft_lstdelone
	ft_putstr_fd("\n---------------ft_lstdelone------------\n",1);
	ft_putstr_fd("original : ",1);
	ft_putlst(test);
	ft_putstr_fd("adding 1998 : ",1);
	ft_lstadd_back(&test,ft_lstnew(ft_strdup("1998")));
	ft_putlst(test);
	ft_putstr_fd("freeing 1998 : ",1);
	ft_lstdelone(ft_lstlast(test),ft_freenode);
	ft_putlst(test);
	//ft_lstdelone(test);
}
