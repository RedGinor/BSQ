/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "include/my.h"

int error_handler(char *buf, int len)
{
    for (; *buf != '\n'; *buf++, len--);
    *buf++;
    len--;
    for (; len > 0; *buf++, len--)
        if (*buf != '.' && *buf != 'o' && *buf != '\n')
            return (84);
    return (0);
}

int my_get_nbr(char *buf)
{
    int i = 0;
    int count = 0;
    int res = 0;

    for (; buf[count] != '\n' && buf[count] != '\0'; count++);
    for (; buf[i] >= '0' && buf[i] <= '9'; i++) {
        res *= 10;
        res += buf[i] - '0';
    }
    if (count != i)
        return (-84);
    return (res);
}

int read_file(int fd, struct stat stats)
{
    char *buf = malloc(sizeof(char) * stats.st_size);
    char **buffer;
    int res = 0;
    int l = 0;

    read(fd, buf, stats.st_size);
    res = my_get_nbr(buf);
    if (res <= 0 || error_handler(buf, stats.st_size) == 84)
        return (84);
    buffer = malloc(sizeof(char *) * res);
    for (int i = 0; i < res; i++)
        buffer[i] = malloc(sizeof(char) * (stats.st_size / res));
    for (; *buf != '\n'; *buf++);
    *buf++;
    for (int i = 0; i < res; i++, *buf++)
        for (int j = 0; *buf != '\0' && *buf != '\n'; *buf++, j++, l = j)
            buffer[i][j] = *buf;
    put_square(buffer, l, res);
    return (0);
}

int main(int ac, char **av)
{
    char *path;
    int fd;
    struct stat stats;

    if (ac == 2) {
        path = av[1];
        fd = open(path, O_RDONLY);
    }
    if (fd < 0)
        return (84);
    stat(path, &stats);
    if (read_file(fd, stats) == 84) {
        close(fd);
        return (84);
    }
    close(fd);
    return (0);
}
