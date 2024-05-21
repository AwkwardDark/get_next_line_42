
#include <fctnl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

char    *get_next_line(int fd)
{ 
    char        *buf;
    char        **buf_stock;
    static char *next_line;
    int         i;
    int         j;
    int         bufchar;
    int         size;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
        return (NULL);
    
    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    i = 0;
    while (!new_line(buf))
        size++;
    buf_stock = malloc(sizeof(char) * size + 1);
    if (!buf_stock)
        return (NULL);
    j = 0;
    while ((bufchar = read(fd, buf, BUFF_SIZE)) && j < size)
    {
        i = 0;
        while (buf[i])
        {
            buf_stock[j][i] = buf[i];
            i++;
        }
        j++;
    }
    nextline = malloc (sizeof(char) * line_len(buf_stock) + 1);
    if (!nextline)
        return (NULL);
}

int line_len(char **buf_stock)
{
    int i;
    int j;
    int len;

    len = 0;
    i = 0;
    while (buf_stock[i])
    {
        j = 0;
        while (buf_stock[i][j])
        {
            if (buf_stock[i][j] != '\n')    
                len++;
            j++;
        }
        i++;
    }
    len++;
    return (len);
}

int new_line(char   *buf)
{
    int i;

    if (!buf)
        return (0);
    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}