#include <stdio.h>
#define MAXLINE 1000    // maximum input line size

int getStringLine(char line[], int maxline);
void reverse(char src[], char dest[],int len);

// print longest input line
int main()
{
    int len;                // current line length
    char line[MAXLINE];     // current input line
    char reversed[MAXLINE];

    while ((len = getStringLine(line, MAXLINE)) > 0)
    {
        reverse(line, reversed, len);
        printf("%s", reversed);
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

void reverse(char src[], char dest[], int len)
{
    int hasNewLine = 0;
    int lengthToReverse = len - 1;  // ignore null character when reversing

    if (src[len-1] == '\n')
    {
        hasNewLine = 1;
        --lengthToReverse;  // if the string has a newline, ignore it too
    }

    for (int i = 0; i <= lengthToReverse; ++i) 
        dest[lengthToReverse - i] = src[i];

    if (hasNewLine)
        dest[len-1] = '\n';

    dest[len] = '\0';
}

