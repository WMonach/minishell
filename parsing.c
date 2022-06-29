#include "minishell.h"

int	check_arg(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac < 3 && *av[1] == '$')
		return (0);
	return (1);
}

void	parsing(int ac, char **av, char **env, t_shell *minishell)
{
	if (check_arg(ac, av) == 0)
		exit_error(minishell);
	// get_path(av, env, minishell);
	env += 0;
}
