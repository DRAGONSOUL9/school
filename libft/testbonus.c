#include "libft.h"

static void	ft_freenode(void *content)
{
	if (!content)
		return ;
	free(content);
}

static void	ft_putlst(t_list *node)
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

static t_list	*ft_lstlong(int start, int end, void (*ft)(t_list**,t_list*))
{
	t_list	*test;

	test = NULL;
        char    *str;
	int	i = start;
        while (i < end)
        {
                str = ft_itoa(i);
                ft(&test,ft_lstnew(str));
                i++;
        }
	return (test);
}

static void	ft_lstdelback(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev;

	if (!lst || !del)
		return ;
	tmp = (*lst);
	prev = NULL;
	while(tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	else
		(*lst) = NULL;
	ft_lstdelone(tmp,del);
}

static void	ft_islstfree(t_list *lst)
{
	if (lst)
                ft_putstr_fd("freeing the node : Failed\n",1);
        else
                ft_putstr_fd("freeing the node : Success\n",1);
}

static void	ft_testiter(void *content)
{
	char	*str;

	str = ft_itoa(ft_atoi((char *)content) + 20);
	ft_strlcpy((char *)content,str,3);
}

static void	*ft_testmap(void *content)
{
	char	*str;

	str = ft_itoa(ft_atoi((char *)content) + 40);
	ft_strlcpy((char *)content,str,3);
	return (str);
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
	test = ft_lstlong(0,10,ft_lstadd_front);
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
        test4 = ft_lstlong(100,110,ft_lstadd_back);
	ft_putlst(test4);
	ft_putstr_fd("\nthis is a test to see if i can concatenate two nodes test and test4\n",1);
	ft_lstadd_back(&test4,test);
	ft_putlst(test4);

	//this code is to seperate test from test4
	t_list *tmp;
	tmp = test4;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->content,"109",3) == 0)
		{
			tmp->next = NULL;
			break;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("\n	after seperating test from test4\n",1);
	ft_putlst(test4);

	//ft_lstdelone
	ft_putstr_fd("\n---------------ft_lstdelone------------\n",1);
	ft_putstr_fd("original : ",1);
	ft_putlst(test);
	ft_putstr_fd("adding 1998 : ",1);
	ft_lstadd_back(&test,ft_lstnew(ft_itoa(1998)));
	ft_putlst(test);
	ft_putstr_fd("freeing 1998 : ",1);
	//ft_lstdelone(ft_lstlast(test),ft_freenode);
	ft_lstdelback(&test,ft_freenode); //this line seperated the node then deletes it
	ft_putlst(test);

	//ft_lstclear
	ft_putstr_fd("\n---------------ft_lstclear------------\n",1);
	ft_lstclear(&test,ft_freenode);
	ft_islstfree(test);
	ft_lstclear(&test4,ft_freenode);
	ft_islstfree(test4);
	test4 = ft_lstlong(0,100,ft_lstadd_back);
	ft_putlst(test4);
	ft_lstclear(&test4,ft_freenode);
	ft_islstfree(test4);

	//ft_lstiter
	ft_putstr_fd("\n---------------ft_lstiter------------\n",1);
	test4 = ft_lstlong(10,20,ft_lstadd_back);
	ft_putstr_fd("before node : ",1);
	ft_putlst(test4);
	ft_lstiter(test4,ft_testiter);
	ft_putstr_fd("after node : ",1);
	ft_putlst(test4);

	//ft_lstmap
	ft_putstr_fd("\n---------------ft_lstmap------------\n",1);
	t_list *map = ft_lstmap(test4,ft_testmap,ft_freenode);
	ft_putlst(map);
}
