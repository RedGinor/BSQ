/*
** EPITECH PROJECT, 2020
** openfile
** File description:
** opens files
*/

#include <unistd.h>
#include "include/struct.h"

int check_square(struct square t, int x, int y, int tmp)
{
    if (t.buf[x][y] == 'o')
        return (0);
    for (int i = 0; i < tmp; i++)
        for (int j = 0; j < tmp; j++)
            if (t.buf[x + i][y + j] != '.')
                return (tmp - 1);
    check_square(t, x, y, tmp + 1);
}

struct square find_square(struct square s)
{
    int mem = 0;
    int pos = 0;

    for (int x = 0; x < s.wdt && s.wdt - x > s.max - 1; x++)
        for (int y = 0; y < s.len && s.len - y > s.max - 1; y++) {
                mem = check_square(s, x, y, s.max);
            if (mem > s.max) {
                s.max = mem;
                s.x = x;
                s.y = y;
            }
        }
    return (s);
}

void put_square(char **buf, int l, int nbr)
{
    int mem = nbr;
    int i = 0;

    sq.buf = buf;
    sq.wdt = nbr - 1;
    sq.len = l;
    if (nbr == 1 && l > 0)
        for (int i = 0; i < l && i >= 0; i++)
            if (buf[0][i] == '.') {
                buf[0][i] = 'x';
                i = -84;
            }
    sq = find_square(sq);
    for (int i = 0; i < sq.max; i++)
        for (int j = 0; j < sq.max; j++)
            buf[sq.x + i][sq.y + j] = 'x';
    for (int i = 0; i < nbr; i++) {
        write(1, buf[i], l);
        write(1, "\n", 1);
    }
}
