/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:41 by ifounas           #+#    #+#             */
/*   Updated: 2025/01/13 18:35:03 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../minilibx-linux/mlx.h"

int fstrlen(char const *s)
{
    int i = 0;
    
    while (s[i])
        i++;
    return (i);
}

int ft_count_words(char const *s, char c)
{
    int nb;
    int i;
    
    nb = 0;
    i = -1;
    while (s[++i])
    {
        if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
            nb++;
    }
    return (nb);
}

static int	ft_free(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (0);
}

int    ret_str(char const *s, char c, char **tab, int y)
{
    int i;
    int j;
    int nb_c;
    char *tmp;
    
    i = -1;
    j = 0;
    while (s[++i])
    {
        if (s[i] == c && i == y)
        {
            while (s[++i] != c)
                nb_c++;
            break;            
        }
    }
    i = -1;
    tab[y] = malloc((nb_c + 1) * sizeof(char));
    if (!tab[y])
        return (ft_free(tab, y));
    while (s[++i])
    {
        if (s[i] == c && i == y)
        {
            while (s[++i] != c)
            {
                tab[y][j] = s[i];
                j++;
            }
            break;
        }
    }
    tab[y][nb_c] = '\0';
    return (1);
}

char    **ft_splitsplit(char const *s, char c)
{
    char **tab;
    int nb;
    int i;

    i = -1;
    nb = ft_count_words(s,c);
    tab = malloc((nb + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    while (++i < nb)
    {
        if (ret_str(s, c, tab, i) == 0)
            return (NULL);
    }
    return (tab);
}


int main()
{
    char **tab = ft_splitsplit(" test c un test", ' ');
    int i;
    
    while (++i < ft_count_words(" test c un test", ' '))
		printf("%s\n", tab[i]);
	free(tab);
}
