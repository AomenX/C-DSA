#include <stdio.h>
#include "hash_set.h"

int contains_duplicate(int *nums, int size)
{
        t_HashSet       set;
        int     i;

        hash_set_init(&set, size);
        i = 0;
        while (i < size)
        {
                if (hash_set_contains(&set, nums[i]))
                {
                        hash_set_destroy(&set);
                        return (1);
                }
                hash_set_insert(&set, nums[i]);
                i++;
        }
        hash_set_destroy(&set);
        return (0);
}

int     main(void)
{
        int nums1[] = {1, 2, 3, 1};
        int nums2[] = {1, 2, 3, 4};

        printf("%d\n", contains_duplicate(nums1, 4));
        printf("%d\n", contains_duplicate(nums2, 4));
}