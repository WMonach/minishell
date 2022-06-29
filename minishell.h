
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
	char	*cmd;
}	t_shell;

void	parsing(int ac, char **av, char **env, t_shell *minishell);
void	init_variable(t_shell *minishell);
void	get_path(char **av, char **env, t_shell *minishell);

/*ERROR*/
void	exit_error(t_shell *minishell);
void	exit_perror(t_shell *minishell, char *error);
void	exit_strerror(t_shell *minishell, char *error);
#endif