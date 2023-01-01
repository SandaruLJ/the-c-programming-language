#include <stdio.h>

#define IN 1    // inside a word
#define OUT 0   // outside a word

int main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && (state == IN))
        {
            state = OUT;
            putchar('\n');  // break line when a word ends
        }
        else
        {
            if (state == OUT)
                state = IN;

            printf("=");
        }
    }

    return 0;
}
