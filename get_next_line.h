/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:27:53 by pajimene          #+#    #+#             */
/*   Updated: 2024/05/23 15:53:55 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//gnl main functions
char	*get_next_line(int fd);
char	*ft_read_line(char *buffer, int fd);
//gnl utils
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
void	*ft_calloc(int size, int number);
char	*ft_join_free(char *buffer, char *temp_buffer);

#endif