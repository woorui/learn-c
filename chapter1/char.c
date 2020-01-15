#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 1-7 打印 EOF
    printf("EOF = %d", EOF);

    // 1-9 替换多个空格为单个空格
    int c, last;
    while ((c = getchar()) != EOF)
    {
        if (!(c == ' ' && last == ' '))
        {
            putchar(c);
        }
        last = c;
    }

    return 0;
}
