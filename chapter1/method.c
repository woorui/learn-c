#include <stdio.h>

#define MAXLINE 1000

int power(int m, int n);
int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    // 打印最长的输入行 -- start
    int len;               // 当前行长度
    int max;               // 目前为止发现的最长行的长度
    char line[MAXLINE];    // 当前的输入行
    char longest[MAXLINE]; // 同于保存最长的行

    max = 0;
    while((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) 
        printf("The longest line is `%s`", longest);
    // 打印最长的输入行 -- end

    // int i;
    // for (i = 0; i < 10; i++)
    //     printf("%d, %d, %d \n", i, power(2, i), power(-3, i));
    return 0;
}

// power 计算base的n次幂
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 0; i < n; i++)
        p *= base;

    return p;
}

// mygetline 将一行读入s中，并返回长度
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

// copy 将from复制到to，这里假设to足够大
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}