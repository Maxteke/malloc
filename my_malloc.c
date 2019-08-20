/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** my_malloc
*/

#include "my_malloc.h"

t_block *g_malloc_block = NULL;

t_block *add_new_block(size_t size)
{
    t_block *tmp = sbrk(0);

    if (sbrk(size + align(sizeof(t_block))) == (void *)-1)
        return (NULL);
    *tmp = init_struct(size, NULL, NULL, tmp + align(sizeof(t_block)));
    return (tmp);
}

t_block *search_block(size_t size)
{
    t_block *tmp = g_malloc_block;
    while (tmp != NULL) {
        if (size + align(sizeof(t_block)) <= tmp->size && tmp->free == 1)
            return (tmp);
        tmp = tmp->next;
    }
    return (tmp);
}

void divide_block(t_block *block, size_t size)
{
    t_block tmp = *block;
    t_block *new = block;
    t_block *rest = (t_block *)block->block + size;

    *new = init_struct(size, NULL, block->prev, block->block);
    *rest = init_struct(tmp.size - size - align(sizeof(t_block)),
        tmp.next, new, (t_block *)tmp.block + size + align(sizeof(t_block)));
    new->next = rest;
}

void *malloc(size_t size)
{
    t_block *tmp = g_malloc_block;
    t_block *prev = tmp;

    size = align(size);
    if (g_malloc_block == NULL) {
        g_malloc_block = add_new_block(size);
        return (g_malloc_block->block);
    } else if ((tmp = search_block(size)) != NULL) {
        divide_block(tmp, size);
        return (tmp->block);
    }
    tmp = g_malloc_block;
    while (tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    tmp = add_new_block(size);
    prev->next = tmp;
    tmp->prev = prev;
    return (tmp->block);
}

void free(void *ptr)
{
    t_block *tmp = g_malloc_block;

    while (tmp != NULL && tmp->block != ptr)
        tmp = tmp->next;
    if (tmp != NULL && tmp->next == NULL) {
        if (tmp->prev != NULL)
            tmp->prev->next = NULL;
        else
            g_malloc_block = NULL;
        brk(tmp);
    }
    else if (tmp != NULL)
        tmp->free = 1;
}