#include <stdio.h>
#define TABSTOP 8       // fixed set of tab stops every 'n' columns
#define MAXLEN 1000     // maximum input string length

int getStringLine(char str[], int maxLen);
void detab(char srcStr[], char destStr[], int tabstop);

int main()
{
    char str[MAXLEN];
    char detabbedStr[MAXLEN];
    int len;

    while ((len = getStringLine(str, MAXLEN)) > 0)
    {
        detab(str, detabbedStr, TABSTOP);
        printf("%s", detabbedStr);
    }

    return 0;
}

// get user input to character array and return its length
int getStringLine(char str[], int maxLen)
{
    int index, charInput;

    for (index = 0; (index < maxLen - 1)
            && (charInput = getchar()) != EOF && charInput != '\n'; ++index)
        str[index] = charInput;

    if (charInput == '\n')
    {
        str[index] = charInput;
        ++index;
    }

    str[index] = '\0';
   
    return index; 
}

// replace tabs with spaces
void detab(char srcStr[], char destStr[], int tabstop)
{
    int srcIdx, destIdx;
    int nextTabstop, requiredSpaces;

    for (srcIdx = 0, destIdx = 0; srcStr[srcIdx] != '\0'; ++srcIdx, ++destIdx)
    {
        if (srcStr[srcIdx] == '\t')
        {
            // find next tabstop in spaces and required spaces to get there
            nextTabstop = ((destIdx + tabstop) / tabstop) * tabstop;
            requiredSpaces = nextTabstop - destIdx;

            // put the required number of spaces in the destination string
            while (requiredSpaces > 0)
            {
                destStr[destIdx] = ' ';

                if (--requiredSpaces)  // increment dest index only if needed
                    ++destIdx;
            }
        }
        else
            destStr[destIdx] = srcStr[srcIdx];
    }

    destStr[destIdx] = '\0';
}

