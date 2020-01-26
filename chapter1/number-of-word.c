#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{

    int c, state;

    state = OUT;

    while ((c = getchar()) != '\n')
    {
        // 当 c 是单词分隔符的时候，输出换行，并且改变state
        if (c == ' ' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n');
                state = OUT;
            }
        }
        // 当c 不是单次分隔符的时候
        else
        {
            // c 是单词的首字母，需要改变state
            if (state == OUT)
            {
                state = IN;
                putchar(c);
            }
            // 不是单次首字母的时候，直接输出就好
            else
            {
                putchar(c);
            }
        }
    }
    putchar('\n');

    return 0;
}
