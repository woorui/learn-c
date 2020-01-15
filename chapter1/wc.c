#include <stdio.h>

#define IN 1  // 在单词内
#define OUT 0 // 在单词外

int main(int argc, char const *argv[])
{
    // // 统计字符个数，单词个数
    // int c, nw, nc, state;

    // state = OUT;
    // nw = nc = 0;

    // while ((c = getchar()) != '\n')
    // {
    //     // 字符数 +1
    //     nc++;

    //     if (c == ' ' || c == '\t')
    //     {
    //         state = OUT;
    //     }
    //     else if (state == OUT)
    //     {
    //         state = IN;
    //         nw++;
    //     }
    // }

    // printf("words count = %d, bytes count = %d \n", nw, nc);


    // 1-12 每行打印一个单词
    int c;

    while ((c = getchar()) != '\n')
    {
        if (c == ' ' || c == '\t')
        {
            printf("\n");
        }
        else {
            putchar(c);
        }
    }

    return 0;
}
