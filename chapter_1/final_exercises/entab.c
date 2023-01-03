#include <stdio.h>
#define TABSTOP 8      // fixed set of tab stops every 'n' columns
#define MAXLEN 1000    // maximum input string length

int getStringLine(char str[], int maxLen);
void entab(char srcStr[], char destStr[], int tabstop);

int main()
{
    char str[MAXLEN];
    char entabbedStr[MAXLEN];
    int len;

    while ((len = getStringLine(str, MAXLEN)) > 0)
    {
        entab(str, entabbedStr, TABSTOP);
        printf("%s", entabbedStr);
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

// replace spaces with tabs
void entab(char srcStr[], char destStr[], int tabstop)
{
    int srcIdx, destIdx;
    int spaceCount;  // for counting consecutive spaces
    int requiredTabs;

    for (srcIdx = 0, destIdx = 0; srcStr[srcIdx] != '\0'; ++srcIdx, ++destIdx)
    {
        if (srcStr[srcIdx] != ' ')
            destStr[destIdx] = srcStr[srcIdx];
        // if a lone space is found and the next char is on a tabstop, replace
        else if (srcStr[srcIdx + 1] != '\0'
                && srcStr[srcIdx + 1] != ' ' && (srcIdx + 1) % tabstop != 0)
            destStr[destIdx] = '\t';
        else
        {
            spaceCount = 0;
            while (srcStr[srcIdx + spaceCount] == ' ')
                ++spaceCount;
            
            requiredTabs = (spaceCount + tabstop - 1) / tabstop;
            while (requiredTabs > 0)
            {
                destStr[destIdx] = '\t';

                if (--requiredTabs)
                    ++destIdx;
            }

            srcIdx += spaceCount - 1;  // Adjust srcIdx for spaces processed
        }
    }
}