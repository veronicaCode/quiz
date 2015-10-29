#include <stdio.h>
#include <string.h>

#define SIZE 30

char find_miniest_ch (char *s, char c, int p)
{
    if ((*(s + p)) == '\0') {
        return (*s);
    }
    if ((*s+p) == c) {
        if (*(s+p+1) != '\0')
            return *(s+p+1);
    } else {
        p++;
        return find_miniest_ch(s, c, p);
    }
    return 0;
}

int main()
{
    char str[30];
    char c;
    int i = 0;
    fgets(str, 30, stdin);
    str[strlen(str)] = '\0';
    for (i = 0; i < strlen(str) - 1; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            printf("The input string should be all lower case!\n");
            return 0;
        }
    }
    c = getchar();
    if (c < 'a' || c > 'z') {
        printf("The input alphabat should be lower case.\n");
        return 0;
    }
    c = find_miniest_ch(&str[0], c, 0);
    putchar(c);
    return 0;
}
