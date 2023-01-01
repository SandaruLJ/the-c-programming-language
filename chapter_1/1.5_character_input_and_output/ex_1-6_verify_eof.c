#include <stdio.h>

int main()
{
    int result;

    result = (getchar() != EOF);
    printf("The value of expression 'getchar() != EOF' is: %d\n", result);

    return 0;
}
