
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_var
{
	void			*content;
	struct s_var	*next;
}					t_var;

typedef struct s_shell
{
	char	*cmd;
	t_var	*envp;
	char	***tokenizers;
}	t_shell;

void	parsing(char **env, t_shell *minishell);
void	init_variable(t_shell *minishell);
void	get_path(char **av, char **env, t_shell *minishell);
void	parse_quote(char *str, t_shell *minishell);
char	*ft_copy_string_without_quote(char *str, char quote);

/*PATH*/
void	get_path(char **av, char **env, t_shell *minishell);

/*LIST*/
t_var	*set_list(t_shell *minishell, int size, char **env);
void	ft_free_list(t_var *list_a);

void	tokenizers_arg(t_shell *minishell);

/*ERROR*/
void	exit_error(t_shell *minishell);
void	exit_perror(t_shell *minishell, char *error);
void	exit_strerror(t_shell *minishell, char *error);

void	free_all(t_shell *minishell);
#endif