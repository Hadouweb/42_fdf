#include "fdf.h"

void	ft_clear_list(t_line *lst)
{
	t_line	*l;
	char	*tmp;

	l = NULL;
	while (lst)
	{	
		l = lst;
		tmp = l->str;
		lst = lst->next;
		free(l);
		l = NULL;
		ft_strdel(&tmp);
	}	
	free(lst);
	lst = NULL;
}