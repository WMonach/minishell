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
	// get_path(av, env, minishell);
	tokenizers_arg(ac, av, minishell);
	env += 0;
}

void	tokenizers_arg(int ac, char **av, t_shell *minishell)
{
	int	i;
	int	j;

	i = 0;
	minishell->tokenizers = malloc(sizeof(t_var **) * (ac - 1));
	while (i < ac - 1)
	{
		minishell->tokenizers[i] = ft_split(av[i + 1], ' ');
		i++;
	}
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (minishell->tokenizers[i][j] != NULL)
		{
			printf("%s\n", minishell->tokenizers[i][j]);
			j++;
		}
		i++;
	}
}
