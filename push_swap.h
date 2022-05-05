#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	int				number;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lst_addfront(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstnew_int(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_swap_first(t_list **alst, int num);
void				ft_push(t_list **alst, t_list **new, int which);
void				ft_rotate(t_list **alst, int which);
void				ft_reverse_rotate(t_list **alst, int num);
void				ft_sort_linked(t_list **a_list, int argc);
long				ft_atoi(const char *str);
int					mid_argv(t_list **lst);
int					ft_check(char **argv);
int					*ft_make_tab(char **argv, int argc);
long				make_binary(int decimalnum);
int					check_digit(int num, int max);
int					top_list(t_list **lst);
int					make_decimal(long long n);
int					ft_check_sorted(char **argv, int argc);
void				ft_sort_five(t_list **a_list);
int					check_list(t_list *a_list);
int					cut_main(int *stock, t_list **a_list, int *tab,
						char **argv);
int					*cut_make_tab(int i, int argc, int *tab);
void				cut_sort_five(t_list **a_list, t_list **b_list);
void				cut_sort(t_list **a_list, int num, t_list **b_list);
int					error_main(void);
int					temp_strlen(char *s);
void				free_list(t_list **a_list, int *tab);
char				**ft_split(char const *s, char c);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
char				**make_argvv(char **argv);
unsigned int		ft_strlcpy(char *dst, char *src, unsigned int size);
void				ft_sort_three(t_list **a_list);
int					cut_ft_check(char **argv, int i);

#endif
