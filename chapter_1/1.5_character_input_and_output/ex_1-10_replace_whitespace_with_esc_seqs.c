#include <stdio.h>

int main()
{
    int input;

    while ((input = getchar()) != EOF)
    {
        if (input == '\t')
            printf("\\t");
        else if (input == '\b')
            printf("\\b");
        else if (input == '\\')
            printf("\\\\");
        else
            putchar(input);
    }

    return 0;
}
