#include <stdio.h>
#include <string.h>

char find_miniest_ch (char *s, char c, int p)
{
    if ((*(s + p)) == '\0'){
        return (*s);
    }
    if ((*s+p) == c) {
        if (*(s+p+1) != '\0') 
            return *(s+1);
    }
    else {
        p++;
        return find_miniest_ch(s, c, p);
    }
}

int main()
{
    char str[30];
    char c;
    gets(str);
    str[strlen(str)] = '\0';
    c = getchar();
    c = find_miniest_ch(&str, c, 0);
    putchar(c);
    return 0;
}
