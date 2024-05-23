/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:27:18 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/23 16:22:11 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buffer, int fd)
{
	char	*temp_buffer;
	int		char_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[char_read] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (buffer);
}

char	*ft_write_line(char *buffer)
{
	int		len;
	char	*next_line;

	len = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	next_line = ft_calloc(sizeof(char), len + 2);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		next_line[len] = buffer[len];
		len++;
	}
	if (buffer[len] && buffer[len] == '\n')
		next_line[len++] = '\n';
	return (next_line);
}

char	*ft_clean_buffer(char *buffer)
{
	char	*new_buffer;
	int		len;
	int		i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}	
	new_buffer = ft_calloc(sizeof(char), ft_strlen(buffer) - len + 1);
	i = 0;
	len++;
	while (buffer[len + i])
	{
		new_buffer[i] = buffer[len + i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_line(buffer, fd);
	if (!buffer)
		return (NULL);
	next_line = ft_write_line(buffer);
	buffer = ft_clean_buffer(buffer);
	return (next_line);
}

// int	main(int ac, char **av)
// {
// 	int	fd;
// 	int	i;

// 	if (ac != 2)
// 	{
// 		if (ac < 2)
// 			printf("File name missing.\n");
// 		if (ac > 2)
// 			printf("Too many arguments.\n");
// 		return (1);
// 	}
// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("Cannot read file.\n");
// 			return (1);
// 		}
// 		i = 1;
// 		while (i < 10)
// 			printf("call n*%d -> %s", i++, get_next_line(fd));
// 		close(fd);
// 	}
// 	return (0);
// }
