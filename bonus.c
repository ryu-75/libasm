#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_list {
    void    *data;
    struct s_list *next;
}       t_list;

extern int  ft_list_size(t_list *begin_list);

void    ft_push(t_list **list, t_list *new);
void    printList(t_list *head);
t_list  *lst_new(void *content);


int main() {
    t_list  *head = NULL;

    ft_push(&head, lst_new("Salut"));
	ft_push(&head, lst_new("bien"));
	ft_push(&head, lst_new("ou"));
	ft_push(&head, lst_new("bien"));

    printf("\e[92mft_list_size:\e[0m %d\n", ft_list_size(head));
    return 0;
}

void    ft_push(t_list **lst, t_list *new) {
    new->next = *lst;
    *lst = new;
}

void printList(t_list *head)
{
    t_list  *temp = head;

    while(temp != NULL)
    {
        printf("%p->", temp->data);
        temp = temp->next;
    }
}

t_list *lst_new(void *content) {
    t_list *new = (t_list *)malloc(sizeof(t_list));

    if (new == NULL) return NULL;

    new->data = content;
    new->next = NULL;
    return new;
}
