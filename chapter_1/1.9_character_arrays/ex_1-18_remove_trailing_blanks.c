#include <stdio.h>
#define MAXLINE 1000    // maximum input line size

int getStringLine(char line[], int maxline);
void removeTrailingBlanks(char str[], int len);

// print longest input line
int main()
{
    int len;                // current line length
    char line[MAXLINE];     // current input line

    while ((len = getStringLine(line, MAXLINE)) > 0)
    {
        removeTrailingBlanks(line, len);
        printf("%s", line);
    }

    return 0;
}

// getStringLine(): read a line into s, return length
int getStringLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/* removeTrailingBlanks(): replace whitespace chars with null characters starting from the end.
 * when a non-whitespace char is found, return.
 */
void removeTrailingBlanks(char str[], int len)
{
    for (int i = len-1; i >= 0; --i) 
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            str[i] = '\0';
        else
        {
            // if next char isn't the terminating char, replace it with newline
            if (i+1 < len)
                str[i+1] = '\n';
            
            return;
        }
    }
}

