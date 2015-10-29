#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

int main()
{
    char str[SIZE];
    char c;
    int i = 0;
    if (!fgets(str, SIZE, stdin)) {
        return 0;
    }
    for (i = 0; i < strlen(str)-1; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            printf("The string should be all low case!\n");
            return 0;
        }
    }
    c = getchar();
    if (c <= 'a' || str[i] >= 'z') {
        printf("Invalid input, please input low case alphabt.\n");
    }
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
