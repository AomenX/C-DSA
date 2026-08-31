#include <stdio.h>
#include <string.h>

int     is_anagram(char *s, char *t)
{
        int     i = 0;
        int     count[26] = {0};

        /* Anagrams must have the same length. */
        if (strlen(s) != strlen(t))
                return (0);
        
        /* Count each character in the first string. */
        while (s[i])
        {
                count[s[i] - 'a']++;
                i++;
        }

        /* Remove each character found in the second string. */
        i = 0;
        while (t[i])
        {
                count[t[i] - 'a']--;
                i++;
        }

        /* * For anagrams, every character count must return to zero.
        * A non-zero count means the strings contain different frequencies. */
        i = 0;
        while (i < 26)
        {
                if (count[i] != 0)
                        return (0);
                i++;
        }
        return (1);
}

int     main(void)
{
        printf("%d\n", is_anagram("anagram", "nagaram")); /* 1 */
        printf("%d\n", is_anagram("rat", "car")); /* 0 */
        printf("%d\n", is_anagram("a", "a")); /* 1 */
        printf("%d\n", is_anagram("a", "b")); /* 0 */
        return (0);
}