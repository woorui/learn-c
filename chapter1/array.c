#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
    // int c, i, nwhite, nother;
    // int ndigit[10];

    // nwhite = nother = 0;

    // for (i = 0; i < 10; i++)
    // {
    //     ndigit[i] = 0;
    // }

    // // 输入读取不到 EOF， 只能读取到回车换行
    // while ((c = getchar()) !=  '\n')
    // {
    //     if (c >= '0' && c <= '9')
    //     {
    //         ++ndigit[c - '0'];
    //     }
    //     else if (c == ' ')
    //     {
    //         ++nwhite;
    //     }
    //     else
    //     {
    //         ++nother;
    //     }
    // }
    // printf("digits = ");

    // for (i = 0; i < 10; ++i)
    // {
    //     printf("%d ", ndigit[i]);
    // }
    // printf(", white space = %d, other = %d \n", nwhite, nother);

    // 1-13 读取输入的单词长度直方图  水平方向
    int c, nc, state;

    state = OUT;
    nc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                putchar(':');
                for (int i = 0; i < nc; i++)
                    putchar('*');
                putchar('\n');
            }
            state = OUT;
            nc = 0;
        }
        else
        {
            state = IN;
            putchar(c);
            ++nc;
        }
    }
    return 0;
}
