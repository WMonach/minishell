#include "minishell.h"

int	main(int argc, char **env)
{
	t_shell	*minishell;

	if (argc == 100)
		return (1);
	while (1)
	{
		minishell = malloc(sizeof(t_shell));
		init_variable(minishell);
		minishell->cmd = readline(NULL);
		printf("readline = %s\n", minishell->cmd);
		parsing(env, minishell);
	}
	return (0);
}
