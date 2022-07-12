#include "minishell.h"

int	check_arg(int ac)
{
	if (ac < 2)
		return (0);
	return (1);
}

void	parsing(int ac, char **av, char **env, t_shell *minishell)
{
	if (check_arg(ac) == 0)
		exit_error(minishell);
	tokenizers_arg(ac, av, minishell);
	env += 0;
}

void	tokenizers_arg(int ac, char **av, t_shell *minishell)
{
	
}
