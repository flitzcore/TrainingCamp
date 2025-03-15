#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_distinct_characters(const char *a)
{
    int count = 0;
    int char_seen[26] = {0}; // Array to track seen characters ('a' to 'z')

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (!char_seen[a[i] - 'a']) // If character not seen before
        {
            char_seen[a[i] - 'a'] = 1;
            count++;
        }
    }
    return count;
}
int count_distinct_characters2(const char *a)
{
    int count = 0;
    char distinct_characters[strlen(a)]; // Temporary array to store unique characters

    for (int i = 0; a[i] != '\0'; i++)
    {
        int is_unique = 1; // Assume current character is unique

        for (int j = 0; j < count; j++)
        {
            if (a[i] == distinct_characters[j])
            {
                is_unique = 0; // Character already exists in distinct_characters
                break;         // No need to check further
            }
        }

        if (is_unique)
        {
            distinct_characters[count] = a[i]; // Store new unique character
            count++;
        }
    }

    return count;
}

int main()
{
    char keyword[1024];
    scanf("%s", keyword);
    printf("%d\n", count_distinct_characters(keyword));
    printf("%d\n", count_distinct_characters2(keyword));
}