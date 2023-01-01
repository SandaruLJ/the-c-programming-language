#include <stdio.h>

#define MAX_UNIQUE_CHARS 256

int main()
{
    int c;
    int charArray[MAX_UNIQUE_CHARS];

    // initialize character frequency to 0
    for (int i = 0; i < MAX_UNIQUE_CHARS; i++)
        charArray[i] = 0;

    // increment each character's frequency in its corresponding position 
    while ((c = getchar()) != EOF)
        ++charArray[c];

    for (int i = 0; i < MAX_UNIQUE_CHARS; i++)
    {
        if (charArray[i] > 0)
        {
            // display escape sequences for invisible characters (tab, newline)
            if (i == '\t')
                printf("\\t\t: ");
            else if (i == '\n')
                printf("\\n\t: ");
            else
                printf("%c\t: ", i);

            for (int j = 0; j < charArray[i]; j++)
                putchar('=');
            putchar('\n');
        }
    }

    return 0;
}
