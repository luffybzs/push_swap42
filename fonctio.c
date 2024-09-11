#include "push_swap.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!str)
		return (free(s1), NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}
void ft_free_tab(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return ;
}
int ft_isdigit_string(char *str)
{
	int j;
	
	j = 0;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+' )
			j++;
		while (str[j] && str[j] >= '0' && str[j] <= '9')
			j++;
		if (str[j] != '\0')
			return (0);
	}
	return (1);
}
int	ft_strlen_tab(char **res)
{
	int i;

	i = 0;
	if (!res)
		return (0);
	while (res[i])
		i++;
	return (i);
}
int 	ft_lstlen(t_lst *lst)
{
	t_node *current;
	int	i;

	i = 0;
	
	current = lst->first;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}