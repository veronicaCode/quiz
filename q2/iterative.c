#include <stdio.h>
#include <string.h>

int main()
{
    char str[30];
    char c;
    gets(str);
    c = getchar();
    int size = strlen(str);
    if (!size)
        return 0;
    for (int i = 0; i < size - 1; i++) {
        if (str[i] == c) {
            putchar(str[i + 1]);
            return 0;
        }
    }
    putchar(str[0]);
    return 0;
}
