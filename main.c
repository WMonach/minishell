#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	*minishell;

	minishell = malloc(sizeof(t_shell));
	init_variable(minishell);
	parsing(ac, av, env, minishell);
	minishell->cmd = readline("try something");
	printf("%s\n", minishell->cmd);
}
