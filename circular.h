#ifndef CIRCULAR_H
# define CIRCULAR_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct	z_list 
{
	int				fd;
	char			*first;
	char			*last;
	struct z_list	*next;
}				h_list;

h_list *lst_get(int fd, h_list **list);
void lst_del(int fd, h_list **list);
void lst_print(h_list *list);
#endif