#include <stdio.h>

#define MAXLINE 1000

int power(int m, int n);
int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
int trim(char str[]);
void myreverse(char str[]);

int main(int argc, char const *argv[])
{
    // 打印最长的输入行 -- start
    int len;               // 当前行长度
    int max;               // 目前为止发现的最长行的长度
    char line[MAXLINE];    // 当前的输入行
    char longest[MAXLINE]; // 同于保存最长的行

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        // 1-16 打印任意长度的line
        printf("The current line is `%s`", line);

        // 1-20 reverse函数
        myreverse(line);
        printf("The reverse returns `%s`", line);

        // 1-18 trim func
        myreverse(line);
        if (trim(line) > 0)
            printf("The trimed line is `%s`", line);

        // 1-17 打印长度大于80个字符的输入行
        if (len > 80)
        {
            printf("Line who's len > 80 is `%s`", line);
        }
        if (len > max)
        {
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

// 1-18 去掉输入行的最后的空格, 并删除完全是空格的行
// 无需删除行中间的空格
int trim(char str[])
{
    int i;

    i = 0;
    while (str[i] != '\n')
        i++;
    i--;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
        i--;

    // 为了顺利打印出char
    if (i >= 0)
    {
        i++;
        str[i] = '\n';
        i++;
        str[i] = '\0';
    }
    return i;
}

// myreverse 函数
void myreverse(char str[])
{
    int i, j;
    char tmp;

    i = 0;
    while (str[i] != '\0')
        i++;
    i--;
    if (str[i] == '\n')
        --i;

    j = 0;

    // 去掉结束符，去掉换行符，
    // 从字符串尾部交换字符串头部,最终结束在字符串中间(while的条件判断)
    while (j < i)
    {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i--;
        j++;
    }
}
