/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:13 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 13:30:59 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>

typedef struct s_env
{
	char			*key;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{
	int				i;
	char			c;
	char			*content;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	int		fd[2];
	int		exit_status;
	int		in;
	int		out;
	int		hd;
	pid_t	pid;
	int		std[2];
	char	*line;
	char	*argv0;
	char	**env1;
	t_token	*token;
	t_env	*env;
}				t_data;

void	ft_init(t_data *a);
void	ft_free_env(t_env *p);
void	ft_free(t_data *a, int i);

int		ft_check_symbol(char c);
void	ft_token_separate(t_data *a);
int		ft_token_and(t_data *a, int i);
int		ft_token_word(t_data *a, int i);
int		ft_token_quote(t_data *a, int i);
int		ft_token_redir(t_data *a, int i);
int		ft_token_dquote(t_data *a, int i);
int		check_next_token(t_data *a, char b);
int		ft_token_pipeline(t_data *a, int i);
int		ft_token_wildcard(t_data *a, int i);
int		ft_token_parenthesis(t_data *a, int i);
int		ft_token_dollar(t_data *a, int i, int j);
void	ft_new_token(t_data *a, char c, char *s, int i);

void	ft_lexer(t_data *a, int i);
char	*ft_join_tokens(char *s1, char *s2);
void	ft_lex_cmd(t_token *tmp, t_token *tmp2);
int		ft_lexer_error(t_token *tmp2, t_data *a);

int		ft_access(char *s);
char	*ft_cmdsub(char *tmp, int i);
void	ft_check_dir(char *s, int i);
char	*ft_cmd_add(t_token *tmp, t_env *tmpe);
void	ft_exec(t_data *a, t_token *tmp, int i);
void	ft_execute(t_data *a, int i, t_token *tmp);
int		ft_here_doc_create(char *s2, t_data *a, int in);
t_token	*ft_exec_redir(t_data *a, t_token *tmp, int i, int j);
t_token	*ft_delete_token(t_data *a, t_token *tmp, t_token *tmp2);

void	ft_signals(char c);
void	ft_signals_default(void);

int		check_build_in(char *s, t_data *a, int k);
int		ft_exit(char *s, int j);
void	ft_pwd(t_data *a);
void	ft_env(char *s, t_data *a, t_env *env);
void	ft_echo(char *s, t_data *a);
void	ft_cd(char *s, t_data *a, t_env *env);
void	ft_unset(char *s, t_data *a);
void	ft_export(char *s, t_data *a, t_env *env);
void	ft_exp_uns_sub(char *s, t_data *a, char c, int i);
void	ft_put_in_env(char *s, t_env *env, t_data *a);

#endif