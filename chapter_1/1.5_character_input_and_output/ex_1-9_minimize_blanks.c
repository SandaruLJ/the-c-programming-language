#include <stdio.h>

int main()
{
    int input;
    int prevChar;

    /* print a character only if it's not a blank
     * or the previous character was not a blank
     */
    while ((input = getchar()) != EOF) 
        if (input != ' ' || prevChar != ' ')
        {
            putchar(input);
            prevChar = input;
        }

    return 0;
}
