#include <stdio.h>

#define IN 1    // Inside a word
#define OUT 0   // Outside a word

int main()
{
    int c, state;

    state = IN;

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
            state = OUT;
        else if (state == OUT)  // print a newline when entering a new word
        {
            printf("\n%c", c);
            state = IN;
        }
        else
            putchar(c);
    }

    return 0;
}
