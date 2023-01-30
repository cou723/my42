/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxx.java@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 23:50:00 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/09/20 12:50:06 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_MESSAGE "Error\n"

# include "libft.h"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*pre;
	void			*content;
	struct s_stack	*next;
	void			(*swap)(struct s_stack *stack, t_list **cmd_list);
	void			(*rotate)(struct s_stack *stack, t_list **cmd_list);
	void			(*rev_rotate)(struct s_stack *stack, t_list **cmd_list);
	void			(*push)(struct s_stack *to, struct s_stack *from,
			t_list **cmd_list);
}					t_stack;

typedef enum e_cmd
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}					t_cmd;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_list			*cmd_list;
}					t_stacks;

bool				is_checker_args(int argc, const char *argv[]);
bool				set_args(int *argc, const char **argv[]);
int					free_splitted_strs(char **map);

bool				is_correct_args(int argc, const char *argv[]);
bool				is_only_num(const char *str);
size_t				int_digit(int num);
size_t				get_2base_digit(int num);
long int			ft_atoli(const char *nptr);
bool				is_num_args(int argc, const char **argv);
bool				can_atoi(const char *num_str);
bool				can_atoi_args(int argc, const char **argv);
bool				exists_duplicate_args(int argc, const char **argv);
bool				init(int argc, const char *argv[], t_stacks *stacks);
void				sort(t_stack *a, t_stack *b, t_list **cmd_list);
void				sort_less_than_three(t_stack *stack, t_list **cmd_list);
void				base_sorter(t_stack *main, t_stack *buf, t_list **cmd_list);
bool				is_sorted(t_stack *stack);

void				do_sa(t_stack *stack, t_list **cmd_list);
void				do_sb(t_stack *stack, t_list **cmd_list);
void				do_ss(t_stacks *stacks);
void				do_pa(t_stack *to, t_stack *from, t_list **cmd_list);
void				do_pb(t_stack *to, t_stack *from, t_list **cmd_list);
void				do_ra(t_stack *stack, t_list **cmd_list);
void				do_rb(t_stack *stack, t_list **cmd_list);
void				do_rr(t_stacks *stacks);
void				do_rra(t_stack *stack, t_list **cmd_list);
void				do_rrb(t_stack *stack, t_list **cmd_list);
void				do_rrr(t_stacks *stacks);
void				shortest_rotate(t_stack *stack, t_stack *want_head,
						t_list **cmd_list);
void				cmd_list_put(t_stacks stacks);
void				cmd_put(const t_list *cmd);
void				cmd_optimize(t_list *cmd_list);
void				add_cmd_stacks(t_stacks *stacks, t_cmd cmd);
void				add_cmd(t_list **cmd_list, t_cmd cmd);

t_stack				*stack_new(void *content);
t_stack				*stack_new_sentry(void);
t_stack				*stack_new_int(int nbr);
t_stack				*stack_last(t_stack *stack);
t_stack				*stack_first(t_stack *stack);
t_stack				*stack_sentry(t_stack *stack);
t_stack				*stack_get(t_stack *stack, size_t need_index);
void				stack_swap(t_stack *stack);
void				stack_swap_later(t_stack *first);
void				stack_rotate(t_stack *stack);
void				stack_rev_rotate(t_stack *stack);
void				stack_push(t_stack **stack, t_stack *push);
t_stack				*stack_pop(t_stack *stack);
void				stack_put_str(t_stack *stack);
void				stack_put_int(t_stack *stack);
void				stack_delete(t_stack *stack, void (*del)(void *));
void				stack_clear(t_stack *stack, void (*del)(void *));
size_t				stack_size(t_stack *stack);
t_stack				*stack_max(t_stack *stack);
int					stack_max_int(t_stack *stack);
t_stack				*stack_min(t_stack *stack);
t_stack				*stack_min_ignore(t_stack *stack, int ignore_max);
int					stack_min_int(t_stack *stack);
t_stack				*stack_min_nth(t_stack *stack, size_t nth);
int					stack_int(t_stack *stack);
size_t				get_rotate_count(t_stack *stack, t_stack *dest);
size_t				get_rev_rotate_count(t_stack *stack, t_stack *dest);
void				stack_put_content_int(t_stack *stack);

#endif /* PUSH_SWAP_H */
