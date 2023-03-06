#include <stdio.h>

void Loveyou(int n)
{
    int i = 1;
    while (i <= n)
    {
        i = i * 2; //每次翻倍  ->执行次数和n之间的关系
        printf("I love you %d\n", i);
    }
    printf("I Love you More Than %d\n", n);
}

int main()
{
    Loveyou(100);
}

void Loveyou4Th(int flag[], int n)
{
    printf("I'm Iron Man\n");
    for (int i = 0; i < n; i++)
    {
        if (flag[i] == n)
        {
            printf("I Love You %d\n", n);
            break; //找到后立刻跳出
        }
    }
}