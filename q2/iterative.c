#include <stdio.h>
#include <string.h>

#define SIZE 30

int main()
{
    char str[SIZE];
    char c;
    if (!fgets(str, SIZE, stdin)) {
        return 0;
    }
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
