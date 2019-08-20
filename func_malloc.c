/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** func_malloc
*/

#include "my_malloc.h"

size_t align(size_t size)
{
    if (size % 8 != 0)
        size += 8 - (size % 8);
    return (size);
}

void *realloc(void *ptr, size_t size)
{
    size = align(size);
    return (ptr);
}

t_block init_struct(size_t size, t_block *next, t_block *prev, void *block)
{
    t_block tmp;

    tmp.size = size;
    tmp.free = 0;
    tmp.next = next;
    tmp.prev = prev;
    tmp.block = block;
    return (tmp);
}