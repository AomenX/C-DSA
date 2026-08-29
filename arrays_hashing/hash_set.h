#ifndef HASH_SET_H
 #define HASH_SET_H

#define EMPTY -1

typedef struct s_Hashset
{
    int *table;
    int capacity;
} t_HashSet;

int     hash_set_init(t_HashSet *set, int capacity);
int     hash_set_insert(t_HashSet *set, int value);
int     hash_set_contains(t_HashSet *set, int value);
void    hash_set_destroy(t_HashSet *set);

 #endif