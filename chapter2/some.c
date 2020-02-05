#include <stdio.h>

#define MAXLINE 100

enum loop {NO, YES};

int mystrlen(char s[]);
int mygetline(char line[], int maxline);
int mygetlinev2(char line[], int maxline);

int main(int argc, char const *argv[])
{
    int i, j;
    char s[MAXLINE];

    // j = mygetline(s, MAXLINE);
    // printf("mygetline returns %d \n", j);

    i = mygetlinev2(s, MAXLINE);
    printf("mygetlinev2 returns %d \n", i);
    return 0;
}

// mystrlen 返回s[]的长度
int mystrlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int mygetline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && ((c = getchar()) != EOF && c != '\n'); i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

// 在习题答案中, 用到了枚举, 用枚举控制是否break死循环
int mygetlinev2(char line[], int maxline)
{
    int c, i;

    i = 0;
    while (1 == 1)
    {
        if (i > maxline - 1)
            break;
        else if ((c = getchar()) == EOF)
            break;
        else if (c == '\n')
            break;
        else
            line[++i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}