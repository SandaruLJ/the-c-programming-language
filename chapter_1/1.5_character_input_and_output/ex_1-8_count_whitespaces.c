#include <stdio.h>

int main()
{
    int input;
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    while ((input = getchar()) != EOF)
    {
        if (input == ' ')
            ++blanks;
        else if (input == '\t')
            ++ tabs;
        else if (input == '\n')
            ++newlines;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("New Lines: %d\n", newlines);

    return 0;
}
