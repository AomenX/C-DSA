#include <stdlib.h>
#include <stdio.h>
#include "hash_set.h"

int     hash_set_init(t_HashSet *set, int capacity)
{
        set->capacity = capacity;
        set->table = malloc(sizeof(*set->table) * capacity);
        
        if (!(set->table))
                return (0);
        
        int     i = 0;
        while (i < capacity)
        {
                set->table[i].occupied = 0;
                i++;
        }
        return (1);
}

int     hash_set_hash_index(t_HashSet *set, int value)
{
        int     index;
        
        index = value % set->capacity;
        if (index < 0)
                index += set->capacity;
        return (index);
}

int hash_set_insert(t_HashSet *set, int value)
{
        int     index;
        int     checked;
        
        index = hash_set_hash_index(set, value);
        checked = 0;
        
        while (checked < set->capacity)
        {
                if (!set->table[index].occupied)
                {
                        set->table[index].value = value;
                        set->table[index].occupied = 1;
                        return (1);
                }
                index = (index + 1) % set->capacity;
                checked++;
        }
        return (0);
}

int hash_set_contains(t_HashSet *set, int value)
{
        int     index;
        int     checked;

        index = hash_set_hash_index(set, value);
        checked = 0;

        while (checked < set->capacity)
        {
                if (!set->table[index].occupied)
                        return (0);
                if (set->table[index].value == value)
                        return (1);
                
                index = (index + 1) % set->capacity;
                checked++;
        }
        return (0);
}

void    hash_set_destroy(t_HashSet *set)
{
        free(set->table);
        set->table = NULL;
}