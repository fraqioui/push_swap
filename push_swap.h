/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:43:51 by fraqioui          #+#    #+#             */
/*   Updated: 2022/12/08 08:43:53 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct node
{
	struct node	*prev;
	int			data;
	int			index;
	int			pos_a;
	struct node	*link;
	int			n_moves;
	struct node	*next;
}t_node;

int		ft_atoi(const char *str);
char	**ft_alloc_free(char **arr);
int		ft_words(const char *s2, char c);
char	**ft_split(char const *s, char c);
void	ft_error(void);
int		ft_duplicated(t_node *head, int l_size);
int		ft_sorted(t_node *list, int len);
void	ft_indexing(t_node *list, int len);
void	ft_into_action(t_node **list, int index);
int		ft_size(t_node *list);

int		ft_min_data(t_node *trav, int len);
int		ft_max_data(t_node *trav, int len);
t_node	*ft_min_node(t_node *last, int len);
t_node	*ft_min_n_moves(t_node *last, int len);
t_node	*ft_max_pos_a(t_node *last, int len);

void	ft_algo_of_three(t_node **stack_a, int len);
void	ft_algo_of_five(t_node **stack_a, int len);
void	ft_algo_lis(t_node **stack_a, int len);

void	ft_apply_moves_b(t_node **stack_a, t_node **stack_b, int len);
void	ft_moves_calc(t_node *stack_a, t_node *stack_b, int len_a, int len_b);
void	ft_apply_moves_a_same(t_node **stack_a, t_node **stack_b, t_node *node);
void	ft_apply_moves_a_diff(t_node **stack_a, t_node **stack_b, t_node *node);

void	ft_largest_increasing_subsequence(t_node *list, int n);
void	ft_save_lis(t_node *last, int n);

t_node	*ft_new_node(int value);
void	ft_push(t_node **top, t_node *to_add);
void	ft_list_crea(int ac, char **av, t_node **head);
void	ft_pop(t_node **top, int len);

void	ft_swap_a(t_node *a_head);
void	ft_swap_b(t_node *b_head);
void	ft_swap_a_b(t_node *a_head, t_node *b_head);
void	ft_push_a(t_node **a_head, t_node **b_head);
void	ft_push_b(t_node **a_head, t_node **b_head);
void	ft_rotate_a(t_node **a_head);
void	ft_rotate_b(t_node **b_head);
void	ft_rotate_a_b(t_node **a_head, t_node **b_head);
void	ft_rev_rotate_a(t_node **a_head);
void	ft_rev_rotate_b(t_node **b_head);
void	ft_rev_rotate_a_b(t_node **a_head, t_node **b_head);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *s, unsigned int index, size_t len);
char	*ft_get_the_line(int fd, char **str, char *buf);
ssize_t	ft_check_new_line(char *s1);
char	*ft_save(char **s3, size_t n);
char	*ft_free(char **s, char *set);
char	*ft_new_line(char **s2);

#endif
