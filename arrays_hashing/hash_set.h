#ifndef HASH_SET_H
 #define HASH_SET_H

typedef struct  s_HashEntry
{
    int value;
    int occupied;
} t_HashEntry;

typedef struct s_Hashset
{
    t_HashEntry *table;
    int capacity;
} t_HashSet;

int     hash_set_init(t_HashSet *set, int capacity);
int     hash_set_insert(t_HashSet *set, int value);
int     hash_set_contains(t_HashSet *set, int value);
void    hash_set_destroy(t_HashSet *set);
int     hash_set_hash_index(t_HashSet *set, int value);

 #endif