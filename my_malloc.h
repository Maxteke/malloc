/*
** EPITECH PROJECT, 2019
** Repository
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_block
{
    int free;
    void *block;
    size_t size;
    struct s_block *next;
    struct s_block *prev;
}   t_block;

extern t_block *g_malloc_block;

void *malloc(size_t);
void *realloc(void *, size_t);
void  free(void *);
size_t align(size_t);
t_block init_struct(size_t, t_block *, t_block *, void *);
t_block *add_new_block(size_t);
t_block *search_block(size_t);
void divide_block(t_block *, size_t);

#endif /* !MY_MALLOC_H_ */
