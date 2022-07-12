#include "minishell.h"

int	check_arg(int ac)
{
	if (ac < 2)
		return (0);
	return (1);
}

void	parsing(char **env, t_shell *minishell)
{
	tokenizers_arg(minishell);
	env += 0;
}

void	tokenizers_arg(t_shell *minishell)
{

	minishell += 0;
	parse_quote(minishell->cmd, minishell);
	/*
	si une double quote? je met tout dans une liste
	*/
}

void	parse_quote(char *str, t_shell *minishell)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			printf("double quote\n");
			str = ft_copy_string_without_quote(str, '"');
			ft_lstadd_back((t_list **)(&(minishell->envp)),
				ft_lstnew((void *)str));
		}
		i++;
	}
}

char	*ft_copy_string_without_quote(char *str, char quote)
{
	int		i;
	int		j;
	char	*newstr;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == quote)
			j++;
		i++;
	}
	newstr = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != quote)
			newstr[j++] = str[i];
		i++;
	}
	newstr[j] = '\0';
	printf("newstr = %s\n", newstr);
	return (newstr);
}
