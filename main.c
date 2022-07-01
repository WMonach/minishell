#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*minishell;

	minishell = malloc(sizeof(t_shell));
	init_variable(minishell);
	minishell->cmd = readline(NULL);
	parsing(ac, av, env, minishell);
	return (0);
}
