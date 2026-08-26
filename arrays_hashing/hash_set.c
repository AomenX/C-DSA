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
                set->table[i] = EMPTY;
                i++;
        }
        return (1);
}

int hash_set_insert(t_HashSet *set, int value)
{
        int     index;
        int     checked;

        index = value % set->capacity;
        checked = 0;

        while (checked < set->capacity)
        {
                if (set->table[index] == EMPTY)
                {
                        set->table[index] = value;
                        return (1);
                }
                index = (index + 1) % set->capacity;
                checked++;
        }
        return (0);
}
