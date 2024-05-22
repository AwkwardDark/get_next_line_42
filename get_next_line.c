/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:27:18 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/22 19:18:00 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buffer, int fd)
{
	char	*temp_buffer;
	int		char_read;
	int		i;

	temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	while ((char_read = read(fd, temp_buffer, BUFFER_SIZE)))
	{
		i = 0;
		if (!temp_buffer)
			return (NULL);
		temp_buffer[char_read] = '\0';
		ft_strjoin(buffer, temp_buffer);
		while (i < char_read)
		{
			if (temp_buffer[i] == '\n')
				break ;
			i++;
		}
		free(temp_buffer);
	}
	return (buffer);
}

// char	*ft_write_line(char *buffer)
// {
	
// }

// char	*ft_clean_buffer(char *buffer)
// {
	
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	// char	*next_line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	
	buffer = ft_read_line(buffer, fd);
	if (!buffer)
		return (NULL);
	// next_line = ft_write_line(buffer);
	// buffer = ft_clean_buffer(buffer);
	return (buffer);
}

int	main(int ac, char **av)
{
	int	fd;
	
	if (ac != 2)
	{
		if (ac < 2)
			printf("File name missing.\n");
		if (ac > 2)
			printf("Too many arguments.\n");
		return (1);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot read file.\n");
			return (1);
		}
		printf("%s\n", get_next_line(fd));
		close(fd);
	}
	return (0);
}