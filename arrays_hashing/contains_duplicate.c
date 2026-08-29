#include <stdio.h>
#include "hash_set.h"

int main(void)
{
    t_HashSet set;

    if (!hash_set_init(&set, 10))
        return (1);

    hash_set_insert(&set, 12);
    hash_set_insert(&set, 42);
    hash_set_insert(&set, 43);
    hash_set_insert(&set, 25);
    hash_set_insert(&set, 31);

    printf("42: %d\n", hash_set_contains(&set, 42));
    printf("99: %d\n", hash_set_contains(&set, 99));
    printf("43: %d\n", hash_set_contains(&set, 43));

    return (0);
}