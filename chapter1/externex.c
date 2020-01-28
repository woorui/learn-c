#include <stdio.h>

#define MAXLINE 1000

// define 分配存储单元，外部变量只说明变量的性质不分配存储单元

// 外部变量
// 可以全局访问，函数之间可以传递数据
// 在程序执行期间一直存在
// 一般会把所有外部变量的的定义放在源文件的开头
int max;
char line[MAXLINE];
char longest[MAXLINE];

int mygetline(void);
void copy(void);

int main(int argc, char const *argv[])
{
    // len 是自由变量，也就是局部变量，
    // 只能在当前函数中使用，函数执行完毕会消失
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = mygetline()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }
    if (max > 0)
        printf("The longest line is %s", longest);
    return 0;
}

int mygetline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF && c != '\n'); i++)
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

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        i++;
}
