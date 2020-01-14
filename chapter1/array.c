#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; i++)
    {
        ndigit[i] = 0;
    }

    // 输入读取不到 EOF， 只能读取到回车换行
    while ((c = getchar()) !=  '\n')
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if (c == ' ')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }
    printf("digits = ");

    for (i = 0; i < 10; ++i)
    {
        printf("%d ", ndigit[i]);
    }
    printf(", white space = %d, other = %d \n", nwhite, nother);

    return 0;
}
